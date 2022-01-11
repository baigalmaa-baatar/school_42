/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:31:33 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/09 18:19:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <time.h>
# include <errno.h>
# include <sys/time.h>

# define ERR_ARG "Argument error\n"
# define ERR_CRT "Failed to create thread\n"
# define ERR_JOIN "Failed to join thread\n"
# define ERR_INIT "Failed to initiliaze\n"
# define ERR_DETECTD "Failed to detect death\n"

typedef struct s_in_v
{
	unsigned int		philo_nbr;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	ttosleep;
	unsigned long long	must_eat_nbr;
}	t_in_v;

typedef struct s_philo
{
	bool				*running;
	pthread_mutex_t		fork;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		*message;
	pthread_mutex_t		*running_mutex;
	unsigned long long	start_time;
	unsigned long long	lta;
	unsigned long long	pid;
	t_in_v				in_v;
}	t_philo;

int					ft_atoi(const char *str);
int					str_err(char *str, int ret);
int					init(t_in_v *in_v, t_philo *philos);
size_t				ft_strlen(const	char	*str);
unsigned long long	get_time(void);
void				precise_sleep(unsigned long long ms);
int					get_args(int argc, char *argv[], t_in_v *in_v);
void				ft_putnbr_fd(unsigned long long nbr, int fd);
int					create_thrds(t_in_v in_v, t_philo *philos);
void				take_forks(t_philo *philos, pthread_mutex_t *left,
						pthread_mutex_t *right);
void				release_forks(pthread_mutex_t *left,
						pthread_mutex_t *right);
void				eat(t_philo *philos, int *a_cntr);
int					ch_ate_e(int *a_cntr, int must_eat_nbr,
						pthread_mutex_t *left_fork,
						pthread_mutex_t *right_fork);
int					display_stat(t_philo *philos, char *str,
						unsigned long long timeToDo);
int					join_thrd(t_in_v in_v, pthread_t *p_th,
						pthread_t *death_thread);
int					clean_free(t_in_v *in_v, t_philo *philos);
bool				is_running(t_philo *philor);
void				stop_running(t_philo *philor);
pthread_mutex_t		*resolve_f_fork(t_philo *philor);
pthread_mutex_t		*resolve_s_fork(t_philo *philor);
void				precise_sleep(unsigned long long ms);

#endif
