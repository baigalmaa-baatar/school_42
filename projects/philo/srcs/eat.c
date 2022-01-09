/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:33:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:40:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philo *philos, int *ate_cntr)
{
	pthread_mutex_lock(&philos->eat_mutex);
	philos->lta = get_time();
	pthread_mutex_unlock(&philos->eat_mutex);
	display_stat(philos, " is eating\n", philos->input_val.time_to_eat);
	(*ate_cntr)++;
}
