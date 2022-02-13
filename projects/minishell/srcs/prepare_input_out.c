/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_input_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:48:05 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:03:34 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*tmp_file_name(char *format, int id)
{
	char	*id_str;
	char	*result;

	id_str = ft_itoa(id);
	result = ft_strjoin(format, id_str);
	free(id_str);
	return (result);
}

int	prepare_error(char *filename)
{
	error_fct2(filename, 1);
	return (0);
}

int	prepare_in_hered(t_data *data, int process_id, char	**inputs, int i)
{
	char	*filename;
	bool	do_eval;

	do_eval = false;
	if (inputs[i * 2] == (char *)1)
		do_eval = true;
	filename = tmp_file_name("/tmp/minishell.", process_id);
	if (!prepare_heredoc(data, filename, inputs[i * 2 + 1], do_eval))
	{
		free(filename);
		return (0);
	}
	data->process[process_id].fd_input = open(filename, O_RDONLY);
	free(filename);
	return (1);
}

int	prepare_inputs(t_data *data, int process_id)
{
	int		i;
	char	**inputs;

	inputs = (char **)data->process[process_id].input.elements;
	i = 0;
	while ((size_t) i < data->process[process_id].input.length / 2)
	{
		if (!inputs[i * 2 + 1])
			return (0);
		if (data->process[process_id].fd_input > -1)
			close(data->process[process_id].fd_input);
		if (inputs[i * 2])
		{
			if (!(prepare_in_hered(data, process_id, inputs, i)))
				return (0);
		}
		else
			data->process[process_id].fd_input
				= open(inputs[i * 2 + 1], O_RDONLY);
		if (data->process[process_id].fd_input < 0)
			return (prepare_error(inputs[i * 2 + 1]));
		i++;
	}
	return (1);
}

int	prepare_outputs(t_data *data, int process_id)
{
	int		i;
	char	**outputs;

	outputs = (char **)data->process[process_id].output.elements;
	i = 0;
	while ((size_t) i < data->process[process_id].output.length / 2)
	{
		if (!outputs[i * 2 + 1])
			return (0);
		if (data->process[process_id].fd_output > -1)
			close(data->process[process_id].fd_output);
		if (outputs[i * 2])
			data->process[process_id].fd_output
				= open(outputs[i * 2 + 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		else
			data->process[process_id].fd_output
				= open(outputs[i * 2 + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->process[process_id].fd_output < 0)
			return (prepare_error(outputs[i * 2 + 1]));
		i++;
	}
	return (1);
}
