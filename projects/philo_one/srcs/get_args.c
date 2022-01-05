/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:53:12 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/05 17:53:17 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_args(int argc, char *argv[], t_inputVal *inputVal)
{
	if ((argc == 5 || argc == 6) && ft_atoi(argv[1]) > 1)
	{
		inputVal->philoNbr = ft_atoi(argv[1]);
		inputVal->timeToDie = ft_atoi(argv[2]);
		inputVal->timeToEat = ft_atoi(argv[3]);
		inputVal->timeToSleep = ft_atoi(argv[4]);
		if (argc == 6)
			inputVal->mustEatNbr = ft_atoi(argv[5]);
		else
			inputVal->mustEatNbr = -1;
		return (1);
	}
	return (0);
}
