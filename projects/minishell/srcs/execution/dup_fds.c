/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:52:30 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/14 23:52:33 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	dup_fds(t_data *data, int *stdin_copy, int *stdout_copy)
{	
	if (data->process[0].fd_input > -1)
	{
		*stdin_copy = dup(STDIN_FILENO);
		dup2(data->process[0].fd_input, STDIN_FILENO);
		close(data->process[0].fd_input);
		data->process[0].fd_input = -1;
	}
	if (data->process[0].fd_output > -1)
	{
		*stdout_copy = dup(STDOUT_FILENO);
		dup2(data->process[0].fd_output, STDOUT_FILENO);
		close(data->process[0].fd_output);
		data->process[0].fd_output = -1;
	}
}
