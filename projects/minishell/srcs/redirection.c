/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:19:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/07 00:19:25 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	heredoc_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("\n", STDERR_FILENO);
    close(STDIN_FILENO);
}

void	end_heredoc(char *end)
{
	char	*wanted_end;

    wanted_end = ft_mtp_strjoin("(wanted `", end, "\')");
	if (wanted_end)
	{
		ft_mtp_putendl_fd(STDERR_FILENO,
			"minishell: warning: here-document delimited by end-of-file ",
			wanted_end, NULL);
		free(wanted_end);
	}
}

char    *tmp_file_name(char *format, int id)
{
    char *id_str;
    char *result;

    id_str = ft_itoa(id);
    result = ft_strjoin(format, id_str);
    free(id_str);
    return (result);
}

int     prepare_heredoc(t_data *data, char *filename, char *end)
{
    int     len;
    bool    do_eval;
    int     fd;
    char    *line;
	int		child;
	struct sigaction heredoc_sigint;

	ft_memset(&heredoc_sigint, 0, sizeof(heredoc_sigint));
	len = ft_strlen(end);
	do_eval = false;
	if (len > 2 && end[len - 2] == '"' && end[len - 1] == '"')
		end[len - 2] = 0;
	else
		do_eval = true;
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	g_exit_status = 0;
	child = fork();
	if (child == -1)
		error_fct(data, "minishell: Fork failure: ", 6);
	if (!child)
	{
		heredoc_sigint.sa_handler = &heredoc_sigint_handler;
		sigaction(SIGINT, &heredoc_sigint, NULL);
		while (1)
		{
			line = readline("> ");
			if (g_exit_status == 130)
			{
				free(line);
				rl_clear_history();
				free_data(data);
			//	g_exit_status = 130;
				exit(g_exit_status);
			}
			if (!line)  // = ctrl + d
			{
				end_heredoc(end);
				break ;
			}
			if (ft_strncmp(line, end, len + 1) == 0) // TODO: use simply `ft_strcmp()`
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
    	close(fd);
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
    return (1);
}

int     prepare_redirections(t_data *data)
{
    int i;
	bool error;

    error = false;
	i = data->nb_processes - 1;
    while (i >= 0)
    {
        if (!data->process[i].input && data->process[i].heredoc)
        {
            data->process[i].input = tmp_file_name("/tmp/minishell.", i);
            if (!prepare_heredoc(data, data->process[i].input, data->process[i].heredoc))
            {
				error = true;
            }
        }
        if (data->process[i].input)
        {
            data->process[i].fd_input = open(data->process[i].input, O_RDONLY);
            if (data->process[i].fd_input < 0)
            {
				error = true;
				error_fct2(data->process[i].input, 1);
            }
        }
        if (data->process[i].output)
        {
            if (data->process[i].append)
                data->process[i].fd_output = open(data->process[i].output, O_CREAT | O_RDWR |O_APPEND, 0644);
            else
                data->process[i].fd_output = open(data->process[i].output, O_CREAT | O_RDWR | O_TRUNC, 0644);
            if (data->process[i].fd_output < 0)
            {
				error = true;
				error_fct2(data->process[i].output, 1);
            }
        }
        i--;
    }
	if (error)
	{
		close_redirection_fds(data);
		return (0);
	}
    return (1);
}

void    close_redirection_fds(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_processes)
    {
        if (data->process[i].fd_input > -1)
        {
            close(data->process[i].fd_input);
            data->process[i].fd_input = -1;
        }
        if (data->process[i].fd_output > -1)
        {
            close(data->process[i].fd_output);
            data->process[i].fd_output = -1;
        }
        i++;
    }
}
