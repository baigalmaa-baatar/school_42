/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:19:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/16 00:30:33 by bbaatar          ###   ########.fr       */
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

void	prepare_redirections(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_processes)
	{
		if (!prepare_redirs(data, i))
			data->process[i].error = true;
		i++;
	}
}
