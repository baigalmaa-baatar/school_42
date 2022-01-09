/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:31:33 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/06 03:20:42 by bbaatar          ###   ########.fr       */
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

typedef struct s_input_val
{
	unsigned int		philo_nbr;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	must_eat_nbr;
}	t_input_val;

typedef struct s_philo
{
	bool				*running;
	pthread_mutex_t		fork;
	pthread_mutex_t		*message;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		*running_mutex;
	unsigned long long	start_time;
	unsigned long long	lta;
	unsigned long long	pid;
	t_input_val			input_val;
}	t_philo;

int					ft_atoi(const char *str);
int					str_err(char *str, int ret);
void				init(t_input_val *input_val, t_philo *philos);
size_t				ft_strlen(const	char	*str);
unsigned long long	get_time(void);
void 				precise_sleep(unsigned long long);
int					get_args(int argc, char *argv[], t_input_val *input_val);
void				ft_putnbr_fd(unsigned long long nbr, int fd);
int					create_thrds(t_input_val input_val, t_philo *philos);
void				take_forks(t_philo *philos, pthread_mutex_t *left,
						pthread_mutex_t *right);
void				release_forks(pthread_mutex_t *left,
						pthread_mutex_t *right);
void				eat(t_philo *philos, int *ate_cntr);
int					check_ate_enough(int *ate_cntr, int must_eat_nbr,
						pthread_mutex_t *left_fork,
						pthread_mutex_t *right_fork);
int					display_stat(t_philo *philos, char *str,
						unsigned long long timeToDo);
int					join_thrd(t_input_val input_val, pthread_t *p_th,
						pthread_t *death_thread);
void				eat(t_philo *philos, int *ate_cntr);

#endif
