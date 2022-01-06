/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:47:47 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:47:48 by bbaatar          ###   ########.fr       */
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
