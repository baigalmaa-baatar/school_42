/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:47:39 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:47:40 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	join_thrd(t_in_v in_v, pthread_t *p_th, pthread_t *death_thread)
{
	unsigned int	i;

	i = 0;
	while (i < in_v.philo_nbr)
	{
		if (pthread_join(p_th[i], NULL) != 0)
			return (str_err(ERR_JOIN, 4));
		i++;
	}
	if (pthread_join(*death_thread, NULL) != 0)
		return (str_err(ERR_JOIN, 4));
	return (0);
}
