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

pthread_mutex_t	*resolve_first_fork(t_philo *philosopher)
{
	t_philo			*first_philosopher;

	first_philosopher = philosopher - philosopher->pid;
	if (philosopher->pid % 2 == 0)
		return (&(philosopher->fork));
	if (philosopher->pid == philosopher->input_val.philo_nbr - 1)
		return (&first_philosopher->fork);
	return (&(philosopher[1].fork));
}

pthread_mutex_t	*resolve_second_fork(t_philo *philosopher)
{
	t_philo			*first_philosopher;

	first_philosopher = philosopher - philosopher->pid;
	if (philosopher->pid % 2 == 0)
	{
		if (philosopher->pid == philosopher->input_val.philo_nbr - 1)
			return (&first_philosopher->fork);
		return (&(philosopher[1].fork));
	}
	return (&(philosopher->fork));
}
