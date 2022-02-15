/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:28:26 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/16 00:30:55 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_process(t_process *process)
{
	process->params = NULL;
	process->redirs = new_array();
	process->fd_input = -1;
	process->fd_output = -1;
	process->error = false;
}

void	free_process(t_data *data, int i)
{
	size_t	j;

	if (data->process[i].params)
	{
		ft_free_tab(data->process[i].params);
		data->process[i].params = NULL;
	}
	j = 0;
	while (j < data->process[i].redirs.length / 2)
	{
		free(data->process[i].redirs.elements[j * 2 + 1]);
		data->process[i].redirs.elements[j * 2 + 1] = NULL;
		j++;
	}
	delete_array(&data->process[i].redirs);
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
}

void	free_processes(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_processes)
	{
		free_process(data, i);
		i++;
	}
	free(data->process);
	data->process = NULL;
}

int	count_elements(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	validate_redir(t_process *process)
{
	size_t	i;

	i = 0;
	while (i < process->redirs.length / 2)
	{
		if (process->redirs.elements[i * 2 + 1])
			if (all_space(process->redirs.elements[i * 2 + 1]))
				return (0);
		i++;
	}
	return (1);
}
