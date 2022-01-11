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

int	display_stat(t_philo *philor, char *str, unsigned long long timeToDo)
{
	pthread_mutex_lock(philor->running_mutex);
	if (!*philor->running)
	{
		pthread_mutex_unlock(philor->running_mutex);
		return (0);
	}
	pthread_mutex_unlock(philor->running_mutex);
	pthread_mutex_lock(philor->message);
	ft_putnbr_fd(get_time() - philor->start_time, 1);
	write (1, " ", 1);
	ft_putnbr_fd((philor->pid) + 1, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(philor->message);
	if (timeToDo)
		precise_sleep(timeToDo);
	return (1);
}

void	precise_sleep(unsigned long long ms)
{
	unsigned long long	start_time;

	start_time = get_time();
	while (get_time() - start_time < ms)
		usleep(100);
}
