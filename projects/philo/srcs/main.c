/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:59:00 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:46:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	str_err(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	get_args(int argc, char *argv[], t_in_v *in_v)
{
	if ((argc == 5 || argc == 6))
	{
		in_v->philo_nbr = ft_atoi(argv[1]);
		in_v->time_to_die = ft_atoi(argv[2]);
		in_v->time_to_eat = ft_atoi(argv[3]);
		in_v->ttosleep = ft_atoi(argv[4]);
		if (argc == 6)
			in_v->must_eat_nbr = ft_atoi(argv[5]);
		else
			in_v->must_eat_nbr = -1;
		if (!in_v->philo_nbr || !in_v->time_to_die
			|| !in_v->time_to_eat || !in_v->ttosleep
			|| !in_v->must_eat_nbr)
			return (0);
		return (1);
	}
	return (0);
}

int	init(t_in_v *in_v, t_philo *philors)
{
	unsigned int	i;
	pthread_mutex_t	*message;
	pthread_mutex_t	*running_mutex;

	message = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	running_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!message || !running_mutex)
		return (1);
	pthread_mutex_init(message, NULL);
	pthread_mutex_init(running_mutex, NULL);
	i = 0;
	while (i < in_v->philo_nbr)
	{
		philors[i].pid = i;
		philors[i].lta = get_time();
		philors[i].start_time = philors[i].lta;
		philors[i].running_mutex = running_mutex;
		philors[i].message = message;
		philors[i].in_v = *in_v;
		pthread_mutex_init(&philors[i].fork, NULL);
		pthread_mutex_init(&philors[i].eat_mutex, NULL);
		i++;
	}
	return (0);
}

int	clean_free(t_in_v *in_v, t_philo *philos)
{
	unsigned int	i;

	i = 0;
	while (i < in_v->philo_nbr)
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
	t_in_v				in_v;
	t_philo				*philos;

	if (!(get_args(argc, argv, &in_v)))
		return (str_err(ERR_ARG, 1));
	philos = malloc(sizeof(t_philo) * in_v.philo_nbr);
	if (init(&in_v, philos))
		return (str_err(ERR_INIT, 1) && clean_free(&in_v, philos));
	if (create_thrds(in_v, philos))
		return (str_err(ERR_CRT, 1) && clean_free(&in_v, philos));
	clean_free(&in_v, philos);
	return (0);
}
