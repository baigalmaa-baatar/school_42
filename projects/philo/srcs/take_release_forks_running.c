/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks_running.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:47:47 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:41:35 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philos, pthread_mutex_t *left,
	pthread_mutex_t *right)
{
	pthread_mutex_lock(left);
	pthread_mutex_lock(right);
	display_stat(philos, " has taken a fork\n", 0);
}

void	release_forks(pthread_mutex_t *left, pthread_mutex_t *right)
{
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}

pthread_mutex_t	*resolve_f_fork(t_philo *philor)
{
	t_philo			*first_philor;

	//avoid to data race:
	//if philo is even number (philo_0 or philo2 etc)
	//he will get the first fork. 
	first_philor = philor - philor->pid;
	if (philor->pid % 2 == 0)
		return (&(philor->fork));
	//in case of only 1 philo:
	//he gets first fork first.
	if (philor->pid == philor->in_v.philo_nbr - 1)
		return (&first_philor->fork);
	return (&(philor[1].fork));
}

pthread_mutex_t	*resolve_s_fork(t_philo *philor)
{
	t_philo			*first_philor;

	first_philor = philor - philor->pid;
	if (philor->pid % 2 == 0)
	{
		if (philor->pid == philor->in_v.philo_nbr - 1)
			return (&first_philor->fork);
		return (&(philor[1].fork));
	}
	return (&(philor->fork));
}
