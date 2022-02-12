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

void	free_processes(t_data *data);

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	ft_free_tab(data->path);
	ft_free_tab(data->my_envp);
	free(data->line);
/*	while (i < data->nb_processes)
		ft_free_tab(data->process[i++].params);*/
	free_processes(data);
	//free(data->process);
	rl_clear_history();
}
