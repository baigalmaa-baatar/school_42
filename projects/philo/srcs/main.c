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

void	init(t_input_val *input_val, t_philo *philosophers)
{
	unsigned int	i;
	pthread_mutex_t *message;
	pthread_mutex_t *running_mutex;
	
	message = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	running_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(message, NULL);
	pthread_mutex_init(running_mutex, NULL);
	i = 0;
	while (i < input_val->philo_nbr)
	{
		philosophers[i].pid = i;
		philosophers[i].lta = get_time();
		philosophers[i].start_time = philosophers[i].lta;
		philosophers[i].running_mutex = running_mutex;
		philosophers[i].message = message;
		philosophers[i].input_val = *input_val;
		pthread_mutex_init(&philosophers[i].fork, NULL);
		pthread_mutex_init(&philosophers[i].eat_mutex, NULL);
		i++;
	}
}

int	clean_free(t_input_val *input_val, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < input_val->philo_nbr)
	{
		pthread_mutex_destroy(&philos[i].fork);
		pthread_mutex_destroy(&philos[i].eat_mutex);
		i++;
	}
	pthread_mutex_destroy(philos->message);
	pthread_mutex_destroy(philos->running_mutex);
	free(philos->message);
	free(philos->running_mutex);
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
	init(&input_val, philos);
	if (create_thrds(input_val, philos))
		return (str_err(ERR_CRT, 1) && clean_free(&input_val, philos));
	clean_free(&input_val, philos);
	return (0);
}
