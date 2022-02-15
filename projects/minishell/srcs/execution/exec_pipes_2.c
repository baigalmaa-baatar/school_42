/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:07:57 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 17:08:01 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	malloc_elements(t_data *data, t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
	elements->child = malloc(sizeof(int) * (nb_pipes + 1));
	if (!elements->child)
		error_fct(data, "minishell: Malloc failure", 2);
	elements->built_in = malloc(sizeof(int) * (nb_pipes + 1));
	if (!elements->built_in)
		error_fct(data, "minishell: Malloc failure", 2);
	elements->pipe_fd = malloc(sizeof(int *) * nb_pipes);
	if (!elements->pipe_fd)
		error_fct(data, "minishell: Malloc failure", 2);
	while (i < nb_pipes)
	{
		elements->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!elements->pipe_fd[i])
			error_fct(data, "minishell: Malloc failure", 2);
		if (pipe(elements->pipe_fd[i]) == -1)
		{
			close_fds(data, elements->pipe_fd, i);
			error_fct(data, "minishell: Pipe failure", 5);
		}
		i++;
	}
}

void	check_all_cmds(t_data *data, t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
	while (i <= nb_pipes)
	{
		if (!data->process[i].params[0])
		{
			elements->built_in[i] = 0;
			i++;
			continue ;
		}
		elements->built_in[i] = find_built_ins(data->process[i].params[0]);
		if (!elements->built_in[i])
			data->process[i].params = find_cmds(data->process[i].params, data);
		i++;
	}
}

void	free_elements(t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		free(elements->pipe_fd[i]);
		i++;
	}
	free(elements->pipe_fd);
	free(elements->built_in);
	free(elements->child);
}

void	close_fds(t_data *data, int **pipe_fd, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (close(pipe_fd[i][0]) == -1)
			error_fct(data, "minishell: Close fd failure", 9);
		if (close(pipe_fd[i][1]) == -1)
			error_fct(data, "minishell: Close fd failure", 9);
		i++;
	}
}
