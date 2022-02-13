/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:28:26 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:04:22 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_process(t_process *process)
{
	process->params = NULL;
	process->input = new_array();
	process->output = new_array();
	process->fd_input = -1;
	process->fd_output = -1;
}

void	free_processes(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < data->nb_processes)
	{
		if (data->process[i].params)
			ft_free_tab(data->process[i].params);
		j = 0;
		while (j < data->process[i].input.length / 2)
		{
			free(data->process[i].input.elements[j * 2 + 1]);
			j++;
		}
		delete_array(&data->process[i].input);
		j = 0;
		while (j < data->process[i].output.length / 2)
		{
			free(data->process[i].output.elements[j * 2 + 1]);
			j++;
		}
		delete_array(&data->process[i].output);
		i++;
	}
	free(data->process);
}

int	count_elements(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

bool	all_space(char *s)
{
	bool	ret;
	int		i;

	ret = false;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	validate_redir(t_process *process)
{
	size_t	i;

	i = 0;
	while (i < process->input.length / 2)
	{
		if (process->input.elements[i * 2 + 1])
			if (all_space(process->input.elements[i * 2 + 1]))
				return (0);
		i++;
	}
	i = 0;
	while (i < process->output.length / 2)
	{
		if (process->output.elements[i * 2 + 1])
			if (all_space(process->output.elements[i * 2 + 1]))
				return (0);
		i++;
	}
	return (1);
}
