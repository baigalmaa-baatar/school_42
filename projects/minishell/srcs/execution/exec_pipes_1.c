/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:07:57 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 17:08:01 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	exec_built_in(t_data *data, t_elements *elements, int i)
{
	if (elements->built_in[i] == 1)
		ft_echo(data->process[i].params);
	else if (elements->built_in[i] == 2)
		ft_env(data->process[0].params, data->my_envp);
	else if (elements->built_in[i] == 3)
		ft_pwd(data->my_envp);
	else if (elements->built_in[i] == 4)
		ft_cd(data->process[i].params, data);
	else if (elements->built_in[i] == 5)
		ft_export(data->process[i].params, data);
	else if (elements->built_in[i] == 6)
		ft_unset(data->process[i].params, data);
	else if (elements->built_in[i] == 7)
		ft_exit(data->process[i].params, data);
}

void	wait_for_childs(t_data *data, t_elements *elements, int nb_pipes)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	data->sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &data->sigint, NULL);
	while (x <= nb_pipes)
	{
		waitpid(elements->child[x], &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		if (WIFSIGNALED(g_exit_status))
		{
			g_exit_status = WTERMSIG(g_exit_status) + 128;
			if (g_exit_status == 130 && !count)
				ft_putstr_fd("\n", STDERR_FILENO);
			else if (g_exit_status == 131 && !count)
				ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
			count++;
		}
		x++;
	}
}

static void	exec_child(t_data *data, t_elements *elements, int nb_pipes, int i)
{
	if (!i)
		first_process(data, elements, i);
	else if (i == nb_pipes)
		last_process(data, elements, i);
	else
		middle_process(data, elements, i);
	close_fds(data, elements->pipe_fd, nb_pipes);
	close_redirection_fds(data);
	if (elements->built_in[i])
		exec_built_in(data, elements, i);
	else if (data->process[i].params && data->process[i].params[0])
	{
		if (execve(data->process[i].params[0],
				data->process[i].params, data->my_envp) == -1)
			error_fct(data, "minishell: Execve failure", 7);
	}
	free_elements(elements, nb_pipes);
	free_data(data);
	exit(g_exit_status);
}

void	exec_processes(t_data *data, t_elements *elements, int nb_pipes)
{
	int					i;
	struct sigaction	child_sigquit;

	i = 0;
	ft_memset(&child_sigquit, 0, sizeof(struct sigaction));
	while (i <= nb_pipes)
	{
		elements->child[i] = fork();
		if (elements->child[i] == -1)
			error_fct(data, "minishell: Fork failure", 6);
		if (!elements->child[i])
		{
			child_sigquit.sa_handler = &child_sigquit_handler;
			sigaction(SIGQUIT, &child_sigquit, NULL);
			exec_child(data, elements, nb_pipes, i);
		}
		i++;
	}
	close_fds(data, elements->pipe_fd, nb_pipes);
	close_redirection_fds(data);
	wait_for_childs(data, elements, nb_pipes);
}

void	exec_pipes(t_data *data, int nb_pipes)
{
	t_elements	elements;

	ft_memset(&elements, 0, sizeof(t_elements));
	malloc_elements(data, &elements, nb_pipes);
	check_all_cmds(data, &elements, nb_pipes);
	exec_processes(data, &elements, nb_pipes);
	data->sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &data->sigint, NULL);
	free_elements(&elements, nb_pipes);
}
