/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:19:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 16:43:28 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

char	*tmp_file_name(char *format, int id)
{
	char	*id_str;
	char	*result;

	id_str = ft_itoa(id);
	result = ft_strjoin(format, id_str);
	free(id_str);
	return (result);
}

void	close_redirection_fds(t_data *data)
{
	int	i;

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

int	prepare_redirections(t_data *data)
{
	int		i;
	bool	error;

	error = false;
	i = data->nb_processes - 1;
	while (i >= 0)
	{
		if (!data->process[i].input && data->process[i].heredoc)
		{
			data->process[i].input = tmp_file_name("/tmp/minishell.", i);
			if (!prepare_heredoc(data, data->process[i].input,
					data->process[i].heredoc))
				error = true;
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
				data->process[i].fd_output = open(data->process[i].output,
						O_CREAT | O_RDWR | O_APPEND, 0644);
			else
				data->process[i].fd_output = open(data->process[i].output,
						O_CREAT | O_RDWR | O_TRUNC, 0644);
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
