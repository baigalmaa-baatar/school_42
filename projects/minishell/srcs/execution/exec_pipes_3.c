/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:07:57 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 17:08:01 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	first_process(t_data *data, t_elements *elements, int i)
{
	if (data->process[i].fd_input > -1)
		dup2(data->process[i].fd_input, 0);
	if (data->process[i].fd_output > -1)
		dup2(data->process[i].fd_output, 1);
	else
		dup2(elements->pipe_fd[i][1], 1);
}

void	middle_process(t_data *data, t_elements *elements, int i)
{
	if (data->process[i].fd_input > -1)
		dup2(data->process[i].fd_input, 0);
	else
		dup2(elements->pipe_fd[i - 1][0], 0);
	if (data->process[i].fd_output > -1)
		dup2(data->process[i].fd_output, 1);
	else
		dup2(elements->pipe_fd[i][1], 1);
}

void	last_process(t_data *data, t_elements *elements, int i)
{
	if (data->process[i].fd_input > -1)
		dup2(data->process[i].fd_input, 0);
	else
		dup2(elements->pipe_fd[i - 1][0], 0);
	if (data->process[i].fd_output > -1)
		dup2(data->process[i].fd_output, 1);
}
