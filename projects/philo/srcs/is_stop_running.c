/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stop_running.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:35:14 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:35:16 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_running(t_philo *philor)
{
	bool			running;

	pthread_mutex_lock(philor->running_mutex);
	running = *philor->running;
	pthread_mutex_unlock(philor->running_mutex);
	return (running);
}

void	stop_running(t_philo *philor)
{
	if (philor->in_v.philo_nbr == 1)
		return ;
	pthread_mutex_lock(philor->running_mutex);
	*philor->running = false;
	pthread_mutex_unlock(philor->running_mutex);
}
