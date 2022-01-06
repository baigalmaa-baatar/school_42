/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:59:00 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:21:50 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	str_err(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	get_args(int argc, char *argv[], t_input_val *input_val)
{
	if ((argc == 5 || argc == 6) && ft_atoi(argv[1]) > 1)
	{
		input_val->philo_nbr = ft_atoi(argv[1]);
		input_val->time_to_die = ft_atoi(argv[2]);
		input_val->time_to_eat = ft_atoi(argv[3]);
		input_val->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			input_val->must_eat_nbr = ft_atoi(argv[5]);
		else
			input_val->must_eat_nbr = -1;
		return (1);
	}
	return (0);
}

int	init(t_input_val *input_val, unsigned long long lta_arr[],
		pthread_mutex_t forks[], pthread_mutex_t *message)
{
	unsigned int	i;

	i = 0;
	while (i < input_val->philo_nbr)
	{
		lta_arr[i] = get_time();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(message, NULL);
	return (1);
}

int	clean(t_input_val *input_val, pthread_mutex_t forks[],
		pthread_mutex_t *message)
{
	unsigned int	i;

	i = 0;
	while (i < input_val->philo_nbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(message);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_input_val			input_val;
	unsigned long long	lta_arr[2000];
	pthread_mutex_t		forks[2000];
	pthread_mutex_t		message;

	if (!(get_args(argc, argv, &input_val)))
		return (str_err(ERR_ARG, 1));
	if (!(init(&input_val, lta_arr, forks, &message)))
		return (str_err(ERR_INIT, 1));
	if (create_thrds(input_val, lta_arr, forks, &message))
		return (str_err(ERR_CRT, 1));
	clean(&input_val, forks, &message);
	return (0);
}
