/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:22:28 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:04:04 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	heredoc_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("\n", STDERR_FILENO);
	close(STDIN_FILENO);
}

void	exit_sigint(int fd, char *line, t_data *data)
{
	free(line);
	rl_clear_history();
	free_data(data);
	close(fd);
	exit(g_exit_status);
}

void	show_heredoc(t_data *data, char *end, int do_eval, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_exit_status == 130)
			exit_sigint(fd, line, data);
		if (!line)
		{
			end_heredoc(end);
			break ;
		}
		if (ft_strcmp(line, end) == 0)
		{
			free(line);
			break ;
		}
		if (do_eval)
			line = eval(line, data);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = NULL;
	}
}

void	exec_heredoc(t_data *data, char *end, bool do_eval, int fd)
{
	int					child;
	struct sigaction	heredoc_sigint;

	ft_memset(&heredoc_sigint, 0, sizeof(struct sigaction));
	child = fork();
	if (child == -1)
		error_fct(data, "minishell: Fork failure: ", 6);
	if (!child)
	{
		heredoc_sigint.sa_handler = &heredoc_sigint_handler;
		sigaction(SIGINT, &heredoc_sigint, NULL);
		show_heredoc(data, end, do_eval, fd);
		close(fd);
		free_data(data);
		rl_clear_history();
		exit(g_exit_status);
	}
	data->sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &data->sigint, NULL);
	waitpid(child, &g_exit_status, 0);
	data->sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &data->sigint, NULL);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	close(fd);
}

int	prepare_heredoc(t_data *data, char *filename, char *end, bool do_eval)
{
	int		fd;
	int		len;

	len = ft_strlen(end);
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	g_exit_status = 0;
	exec_heredoc(data, end, do_eval, fd);
	return (1);
}
