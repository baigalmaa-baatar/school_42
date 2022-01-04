/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:31:33 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/24 16:31:35 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>

#define ERR_ARG "Argument error\n"
#define ERR_CRT "Failed to create thread\n"
#define ERR_JOIN "Failed to join thread\n"
#define ERR_DET "Failed to detach thread\n"
#define ERR_DETECTD "Failed to detect death\n"

typedef struct s_philo
{
	unsigned int philoNum;
	unsigned long long pId;
	unsigned long long *ltaArr;
	pthread_mutex_t *forks;
	pthread_mutex_t *message;
	bool *running;
	int				nbrMustEat;
	unsigned long long	timeToDie;
	unsigned long long	timeToEat;
	unsigned long long	timeToSleep;
	unsigned long long	mustEatNbr;
}	t_philo;

size_t	ft_strlen(const	char	*str);
unsigned long long getTime(void);
void	ft_putnbr_fd(unsigned long long nbr, int fd);
unsigned long long	get_args(int argc, char **argv, unsigned long long inputVal[5]);
void preciseSleep(int ms);

#endif