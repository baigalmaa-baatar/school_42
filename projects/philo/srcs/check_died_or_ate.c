/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_died_or_ate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:47:25 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:47:26 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philo *philos, int *ate_cntr)
{
	philos->lta_arr[philos->pid] = get_time();
	display_stat(philos, " is eating\n", philos->input_val.time_to_eat);
	(*ate_cntr)++;
}

// int	check_philo_died(bool running, pthread_mutex_t *left_fork,
// 	pthread_mutex_t *right_fork)
// {
// 	if (!running)
// 	{
// 		pthread_mutex_unlock(left_fork);
// 		pthread_mutex_unlock(right_fork);
// 		return (0);
// 	}
// 	return (1);
// }

int	check_ate_enough(int *ate_cntr, int must_eat_nbr,
	pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if (*ate_cntr == must_eat_nbr)
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
		return (0);
	}
	return (1);
}
