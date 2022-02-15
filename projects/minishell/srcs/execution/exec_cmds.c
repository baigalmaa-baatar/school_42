/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:56 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 17:03:57 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	restore_fds(int stdin_copy, int stdout_copy)
{
	if (stdin_copy > -1)
	{
		dup2(stdin_copy, STDIN_FILENO);
		close(stdin_copy);
	}
	if (stdout_copy > -1)
	{
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdout_copy);
	}
}

static void	exec_child(int child, t_data *data)
{
	struct sigaction	child_sigquit;

	ft_memset(&child_sigquit, 0, sizeof(struct sigaction));
	if (!child)
	{
		child_sigquit.sa_handler = &child_sigquit_handler;
		sigaction(SIGQUIT, &child_sigquit, NULL);
		close_redirection_fds(data);
		if (data->process[0].params)
		{
			if (execve(data->process[0].params[0],
					data->process[0].params, data->my_envp) == -1)
				error_fct(data, "minishell: Execve failure", 7);
		}
		free_data(data);
		exit(g_exit_status);
	}
	data->sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &data->sigint, NULL);
	waitpid(child, &g_exit_status, 0);
	data->sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &data->sigint, NULL);
}

void	exec_no_built_in(t_data *data)
{
	int	child;

	data->process[0].params = find_cmds(data->process[0].params, data);
	if (!data->process[0].params)
		return ;
	child = fork();
	if (child == -1)
		error_fct(data, "minishell: Fork failure", 6);
	exec_child(child, data);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	else if (WIFSIGNALED(g_exit_status))
	{
		g_exit_status = WTERMSIG(g_exit_status) + 128;
		if (g_exit_status == 130)
			ft_putstr_fd("\n", STDERR_FILENO);
		else if (g_exit_status == 131)
			ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	}
}

static void	exec_built_in(int built_in, t_data *data)
{
	if (built_in == 1)
		ft_echo(data->process[0].params);
	else if (built_in == 2)
		ft_env(data->process[0].params, data->my_envp);
	else if (built_in == 3)
		ft_pwd(data->my_envp);
	else if (built_in == 4)
		ft_cd(data->process[0].params, data);
	else if (built_in == 5)
		ft_export(data->process[0].params, data);
	else if (built_in == 6)
		ft_unset(data->process[0].params, data);
	else if (built_in == 7)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_exit(data->process[0].params, data);
	}
}

void	exec_cmds(t_data *data)
{
	int	built_in;
	int	stdin_copy;
	int	stdout_copy;

	stdin_copy = -1;
	stdout_copy = -1;
	if (!data->process[0].params[0])
	{
		close_redirection_fds(data);
		return ;
	}
	dup_fds(data, &stdin_copy, &stdout_copy);
	built_in = find_built_ins(data->process[0].params[0]);
	if (built_in)
		exec_built_in(built_in, data);
	else
		exec_no_built_in(data);
	restore_fds(stdin_copy, stdout_copy);
	close_redirection_fds(data);
}
