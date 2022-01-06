/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:33:17 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 23:33:19 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philo *philos, int *ate_cntr)
{
	philos->lta_arr[philos->pid] = get_time();
	display_stat(philos, " is eating\n", philos->input_val.time_to_eat);
	(*ate_cntr)++;
}
