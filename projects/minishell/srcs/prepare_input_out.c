/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_input_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:48:05 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/15 01:17:20 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	prepare_in_hered(t_data *data, int process_id, int redir_type, char *end)
{
	char	*filename;
	bool	do_eval;
	char	*process_id_str;

	do_eval = false;
	if (redir_type == 1)
		do_eval = true;
	process_id_str = ft_itoa(process_id);
	filename = ft_strjoin("/tmp/minishell.", process_id_str);
	free(process_id_str);
	if (!prepare_heredoc(data, filename, end, do_eval))
	{
		free(filename);
		return (0);
	}
	data->process[process_id].fd_input = open(filename, O_RDONLY);
	free(filename);
	return (1);
}

int	prepare_input(t_data *data, int process_id, char *filename)
{
	if (data->process[process_id].fd_input > -1)
		close(data->process[process_id].fd_input);
	data->process[process_id].fd_input = open(filename, O_RDONLY);
	if (data->process[process_id].fd_input < 0)
	{
		error_fct2(filename, 1);
		return (0);
	}
	return (1);
}

int	prepare_output(t_data *data, int process_id, int redir_type, char *filename)
{
	if (data->process[process_id].fd_output > -1)
		close(data->process[process_id].fd_output);
	if (redir_type == 3)
		data->process[process_id].fd_output = open(filename,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		data->process[process_id].fd_output = open(filename,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->process[process_id].fd_output < 0)
	{
		error_fct2(filename, 1);
		return (0);
	}
	return (1);
}

int	prepare_redir(t_data *data, int process_id, int redir_type, char *redir)
{
	if (!redir)
		return (0);
	if (redir_type == 1 || redir_type == 2)
	{
		if (!(prepare_in_hered(data, process_id, redir_type, redir)))
			return (0);
	}
	else if (redir_type == 0)
	{
		if (!prepare_input(data, process_id, redir))
			return (0);
	}
	else
	{
		if (!prepare_output(data, process_id, redir_type, redir))
			return (0);
	}
	return (1);
}

int	prepare_redirs(t_data *data, int process_id)
{
	int		i;
	long	redir_type;
	char	*redir;

	i = 0;
	while ((size_t) i < data->process[process_id].redirs.length / 2)
	{
		redir_type = (long)data->process[process_id].redirs.elements[i * 2];
		redir = data->process[process_id].redirs.elements[i * 2 + 1];
		if (!prepare_redir(data, process_id, redir_type, redir))
			return (0);
		i++;
	}
	return (1);
}
