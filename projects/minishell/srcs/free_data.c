/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:10 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 16:21:12 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	ft_free_tab(data->path);
	data->path = NULL;
	ft_free_tab(data->my_envp);
	data->my_envp = NULL;
	free(data->line);
	data->line = NULL;
	if (data->process)
	{
		close_redirection_fds(data);
		free_processes(data);
	}
	rl_clear_history();
}
