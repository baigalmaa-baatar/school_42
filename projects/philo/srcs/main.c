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

int	init(t_input_val *input_val, t_philo *philos)
{
	unsigned int	i;
	
	philos->message = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	i = 0;
	while (i < input_val->philo_nbr)
	{
		philos[i].lta = get_time();
		pthread_mutex_init(&philos[i].forks, NULL);
		i++;
	}
	pthread_mutex_init(philos->message, NULL);
	pthread_mutex_init(&philos->eat_mutex, NULL);
	// printf("here\n");
	// pthread_mutex_init(philos->running_mutex, NULL);
	return (1);
}

int	clean_free(t_input_val *input_val, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < input_val->philo_nbr)
	{
		pthread_mutex_destroy(&philos[i].forks);
		i++;
	}
	pthread_mutex_destroy(philos->message);
	pthread_mutex_destroy(&philos->eat_mutex);
	// pthread_mutex_destroy(philos->running_mutex);
	free(philos->message);
	free(philos);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_input_val			input_val;
	t_philo				*philos;
	
	if (!(get_args(argc, argv, &input_val)))
		return (str_err(ERR_ARG, 1));
	philos = malloc(sizeof(t_philo) * input_val.philo_nbr);
	if (!(init(&input_val, philos)))
		return (str_err(ERR_INIT, 1) && clean_free(&input_val, philos));
	if (create_thrds(input_val, philos))
		return (str_err(ERR_CRT, 1) && clean_free(&input_val, philos));
	clean_free(&input_val, philos);
	return (0);
}
