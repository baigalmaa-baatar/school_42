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

int	display_stat(t_philo *philos, char *str, unsigned long long timeToDo)
{
	if (!*philos->running)
		return (0);
	pthread_mutex_lock(philos->message);
	ft_putnbr_fd(get_time(), 1);
	write (1, " ", 1);
	ft_putnbr_fd(philos->pid + 1, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(philos->message);
	if (timeToDo)
		usleep(timeToDo * 1000);
	return (1);
}
