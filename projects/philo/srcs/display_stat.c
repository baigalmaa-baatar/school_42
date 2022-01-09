/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:49:05 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:49:06 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	display_stat(t_philo *philosopher, char *str, unsigned long long timeToDo)
{
	pthread_mutex_lock(philosopher->running_mutex);
	if (!*philosopher->running)
	{
		pthread_mutex_unlock(philosopher->running_mutex);
		return (0);
	}
	pthread_mutex_unlock(philosopher->running_mutex);
	pthread_mutex_lock(philosopher->message);
	ft_putnbr_fd(get_time() - philosopher->start_time, 1);
	write (1, " ", 1);
	ft_putnbr_fd((philosopher->pid) + 1, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(philosopher->message);
	if (timeToDo)
		precise_sleep(timeToDo);
	return (1);
}
