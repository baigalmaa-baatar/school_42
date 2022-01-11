/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thrds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:23:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/11 00:55:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	int					a_cntr;
	pthread_mutex_t		*f_fork;
	pthread_mutex_t		*s_fork;
	t_philo				*philor;

	philor = (t_philo *)arg;
	a_cntr = 0;
	f_fork = resolve_f_fork(philor);
	if (philor->in_v.philo_nbr == 1)
		return (0);
	s_fork = resolve_s_fork(philor);
	usleep((philor->pid % 2) * 15000);
	while (1)
	{
		if (!is_running(philor))
			break ;
		take_forks(philor, f_fork, s_fork);
		eat(philor, &a_cntr);
		if (!ch_ate_e (&a_cntr, (int)philor->in_v.must_eat_nbr, f_fork, s_fork))
			break ;
		release_forks(f_fork, s_fork);
		display_stat(philor, " is sleeping\n", philor->in_v.ttosleep);
		display_stat(philor, " is thinking\n", 0);
	}
	return (NULL);
}

int	small_thread(t_philo *philors)
{
	unsigned long long	delta_lta;
	unsigned int		i;

	i = 0;
	while (i < philors->in_v.philo_nbr)
	{
		pthread_mutex_lock(&philors[i].eat_mutex);
		delta_lta = get_time() - philors[i].lta;
		pthread_mutex_unlock(&philors[i].eat_mutex);
		if (delta_lta >= philors->in_v.time_to_die)
		{
			display_stat(&philors[i], " died\n", 0);
			stop_running(&philors[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*detect_death(void *arg)
{
	t_philo			*philors;

	philors = (t_philo *)arg;
	while (1)
	{
		if (!small_thread(philors))
			break ;
		usleep(5000);
	}
	return (NULL);
}

int	create_thrds(t_in_v in_v, t_philo *philors)
{
	unsigned int		i;
	pthread_t			p_th[2000];
	pthread_t			death_thread;
	bool				running;

	running = true;
	i = 0;
	while (i < in_v.philo_nbr)
	{
		philors[i].running = &running;
		if (pthread_create(&p_th[i], NULL, &routine, &philors[i]) != 0)
			return (str_err(ERR_CRT, 3));
		i++;
	}
	if (pthread_create(&death_thread, NULL, &detect_death, philors) != 0)
		str_err(ERR_CRT, 3);
	i = 0;
	while (i < in_v.philo_nbr)
		if (pthread_join(p_th[i++], NULL) != 0)
			return (str_err(ERR_JOIN, 4));
	stop_running(&philors[0]);
	if (pthread_join(death_thread, NULL) != 0)
		return (str_err(ERR_JOIN, 4));
	return (0);
}
