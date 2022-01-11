/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:49:05 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/11 02:02:40 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	precise_sleep(unsigned long long ms)
{
	unsigned long long	start_time;

	start_time = get_time();
	while (get_time() - start_time < ms)
		usleep(100);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	dis_think(t_philo *philor)
{
	if (philor->in_v.philo_nbr % 2 == 0)
		display_stat(philor, " is thinking\n", 0);
	else
		display_stat(philor, " is thinking\n", max(philor->in_v.time_to_eat + 5
				- philor->in_v.ttosleep, 0));
}

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
