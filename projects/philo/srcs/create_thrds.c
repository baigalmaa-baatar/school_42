/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thrds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:23:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:23:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	int				ate_cntr;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo			*philos;

	philos = (t_philo *)arg;
	ate_cntr = 0;
	if (philos->pid == philos->input_val.philo_nbr - 1) {
		left_fork = &philos->forks[0];
		right_fork = &philos->forks[philos->input_val.philo_nbr - 1];
	} else {
		left_fork = &philos->forks[philos->pid];
		right_fork = &philos->forks[philos->pid + 1];
	}
	//left_fork = &philos->forks[philos->pid];
	//right_fork = &philos->forks[
	//	(philos->pid + 1) % philos->input_val.philo_nbr];
	usleep((philos->pid % 2) * 15000);
	while (1)
	{
		if (!(*philos->running))
			break ;
		take_forks(philos, left_fork, right_fork);
		eat(philos, &ate_cntr);
		if (!check_ate_enough (&ate_cntr, (int)philos->input_val.must_eat_nbr,
				left_fork, right_fork))
			break ;
		release_forks(left_fork, right_fork);
		display_stat(philos, " is sleeping\n", philos->input_val.time_to_sleep);
		display_stat(philos, " is thinking\n", 0);
	}
	return (NULL);
}

int	small_thread(t_philo *philos)
{
	unsigned long long	delta_lta;
	unsigned int		i;

	i = 0;
	while (i < philos->input_val.philo_nbr)
	{
		delta_lta = get_time() - philos->lta_arr[i];
		if (delta_lta >= philos->input_val.time_to_die)
		{
			philos->pid = i;
			display_stat(philos, " died\n", 0);
			*(philos->running) = false;
			return (0);
		}
		i++;
	}
	return (1);
}

void	*detect_death(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (!small_thread(philos))
			break ;
		usleep(5000);
	}
	free(philos);
	return (NULL);
}

pthread_t	create_sub_thread(t_input_val input_val,
	unsigned long long lta_arr[], bool *running,
	pthread_mutex_t *message)
{
	pthread_t	death_thread;
	t_philo		*death_struct;

	death_struct = malloc(sizeof(t_philo));
	death_struct->lta_arr = &lta_arr[0];
	death_struct->running = running;
	death_struct->message = message;
	death_struct->input_val = input_val;
	if (pthread_create(&death_thread, NULL, &detect_death, death_struct) != 0)
		str_err(ERR_CRT, 3);
	return (death_thread);
}

int	create_thrds(t_input_val input_val, unsigned long long lta_arr[],
	pthread_mutex_t forks[], pthread_mutex_t *message)
{
	unsigned int	i;
	pthread_t		p_th[2000];
	pthread_t		death_thread;
	t_philo			philos[2000];
	bool			running;

	running = true;
	i = 0;
	while (i < input_val.philo_nbr)
	{
		philos[i].input_val = input_val;
		philos[i].forks = &forks[0];
		philos[i].lta_arr = &lta_arr[0];
		philos[i].running = &running;
		philos[i].message = message;
		philos[i].pid = i;
		if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
			return (str_err(ERR_CRT, 3));
		i++;
	}
	death_thread = create_sub_thread(input_val, lta_arr, &running, message);
	if (join_thrd(input_val, p_th, &death_thread))
		return (str_err(ERR_JOIN, 4));
	return (0);
}
