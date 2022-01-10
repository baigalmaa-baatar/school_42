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

bool	is_running(t_philo *philosopher)
{
	bool			running;

	pthread_mutex_lock(philosopher->running_mutex);
	running = *philosopher->running;
	pthread_mutex_unlock(philosopher->running_mutex);
	return (running);
}

void	stop_running(t_philo *philosopher)
{
	if (philosopher->input_val.philo_nbr == 1)
		return ;
	pthread_mutex_lock(philosopher->running_mutex);
	*philosopher->running = false;
	pthread_mutex_unlock(philosopher->running_mutex);
}
