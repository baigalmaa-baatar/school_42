/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thrds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:23:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:38:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	int					ate_cntr;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;
	t_philo				*philosopher;

	philosopher = (t_philo *)arg;
	ate_cntr = 0;
	first_fork = resolve_first_fork(philosopher);
	if (philosopher->input_val.philo_nbr == 1)
		return (0);
	second_fork = resolve_second_fork(philosopher);
	usleep((philosopher->pid % 2) * 15000);
	while (1)
	{
		if (!is_running(philosopher))
			break ;
		take_forks(philosopher, first_fork, second_fork);
		eat(philosopher, &ate_cntr);
		if (!check_ate_enough (&ate_cntr, (int)philosopher
				->input_val.must_eat_nbr, first_fork, second_fork))
			break ;
		release_forks(first_fork, second_fork);
		display_stat(philosopher, " is sleeping\n",
			philosopher->input_val.time_to_sleep);
		display_stat(philosopher, " is thinking\n", 0);
	}
	return (NULL);
}

int	small_thread(t_philo *philosophers)
{
	unsigned long long	delta_lta;
	unsigned int		i;

	i = 0;
	while (i < philosophers->input_val.philo_nbr)
	{
		pthread_mutex_lock(&philosophers[i].eat_mutex);
		delta_lta = get_time() - philosophers[i].lta;
		pthread_mutex_unlock(&philosophers[i].eat_mutex);
		if (delta_lta >= philosophers->input_val.time_to_die)
		{
			display_stat(&philosophers[i], " died\n", 0);
			stop_running(&philosophers[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*detect_death(void *arg)
{
	t_philo			*philosophers;

	philosophers = (t_philo *)arg;
	while (1)
	{
		if (!small_thread(philosophers))
			break ;
		usleep(5000);
	}
	return (NULL);
}

int	create_thrds(t_input_val input_val, t_philo *philosophers)
{
	unsigned int		i;
	pthread_t			p_th[2000];
	pthread_t			death_thread;
	bool				running;

	running = true;
	i = 0;
	while (i < input_val.philo_nbr)
	{
		philosophers[i].running = &running;
		if (pthread_create(&p_th[i], NULL, &routine, &philosophers[i]) != 0)
			return (str_err(ERR_CRT, 3));
		i++;
	}
	if (pthread_create(&death_thread, NULL, &detect_death, philosophers) != 0)
		str_err(ERR_CRT, 3);
	i = 0;
	while (i < input_val.philo_nbr)
		if (pthread_join(p_th[i++], NULL) != 0)
			return (str_err(ERR_JOIN, 4));
	stop_running(&philosophers[0]);
	if (pthread_join(death_thread, NULL) != 0)
		return (str_err(ERR_JOIN, 4));
	return (0);
}
