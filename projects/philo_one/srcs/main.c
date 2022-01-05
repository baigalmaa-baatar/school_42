/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:57:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:57:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int str_err(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

void display_stat(pthread_mutex_t *lock, unsigned long long pId, char *str, unsigned long long timeToDo)
{
	pthread_mutex_lock(lock);
	ft_putnbr_fd(getTime(), 1);
	write(1," ", 1);
	ft_putnbr_fd(pId + 1, 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(lock);
	usleep(timeToDo * 1000);
}

int	checkPhiloDied(bool running, pthread_mutex_t *leftFork, pthread_mutex_t *rightFork)
{
	if (!running)
		{
			pthread_mutex_unlock(leftFork);
			pthread_mutex_unlock(rightFork);
			return (0);
		}
	return (1);
}

int	checkAteEnough(int	*ateCntr, int mustEatNbr, pthread_mutex_t *leftFork, pthread_mutex_t *rightFork)
{
	if (*ateCntr == mustEatNbr)
	{
		pthread_mutex_unlock(rightFork);
		pthread_mutex_unlock(leftFork);
		return (0);
	}
	else
		(*ateCntr)++;
	return (1);
}

void    *routine(void *arg)
{
	int ateCntr;
	pthread_mutex_t *leftFork;
	pthread_mutex_t *rightFork;
	t_philo *philos;

	philos = (t_philo *)arg;
	ateCntr = 0;
	while (1)
	{
		if (!(*philos->running))
			break;
		leftFork = &philos->forks[philos->pId];
		rightFork = &philos->forks[(philos->pId + 1) % philos->philoNum];
		if (philos->pId % 2)
			usleep((float)philos->timeToDie * 0.9 + 1);
		pthread_mutex_lock(leftFork);
		pthread_mutex_lock(rightFork);
		if (!checkPhiloDied(*(philos->running), leftFork, rightFork))
			break;
		display_stat(philos->message, philos->pId," has taken a fork\n", 0);
		if (!checkPhiloDied(*(philos->running), leftFork, rightFork))
			break;
		if (!checkAteEnough(&ateCntr, (int)philos->mustEatNbr, leftFork, rightFork))
			break;
		philos->ltaArr[philos->pId] = getTime();
		display_stat(philos->message, philos->pId," is eating\n", philos->timeToEat);
		pthread_mutex_unlock(leftFork);
		pthread_mutex_unlock(rightFork);
		if (!(*philos->running))
			break;
		display_stat(philos->message, philos->pId," is sleeping\n", philos->timeToSleep);
		if (!(*philos->running))
			break;
		display_stat(philos->message, philos->pId," is thinking\n", 0);
	}
	return (NULL);
}

bool	init_philos(t_philo *philos, int philoNum)
{
	philos->philoNum = philoNum;
	philos->pId = 0;
	return (true);
}

int small_thread(t_philo *philos, unsigned long long deltaLTA)
{
	unsigned int i;
	i = 0;
	while(i < philos->philoNum)
	{
		deltaLTA = getTime() - philos->ltaArr[i];
		if (deltaLTA >= philos->timeToDie)
		{
			display_stat(philos->message, i," died\n", 0);
			*(philos->running) = false;
			return (0);
		}
		i++;
	}
	return (1);
}

void    *detectDeath(void *arg)
{
	unsigned long long deltaLTA;
	t_philo *philos;

	philos = (t_philo *)arg;
	deltaLTA = 0;
	while (1)
	{
		if (!small_thread(philos, deltaLTA))
			return (NULL);
		usleep(5000);
	}
	return (NULL);
}

int	joinThr(unsigned long long philoNbr, pthread_t *p_th)
{
	unsigned int i;

	i = 0;
	while(i < philoNbr)
	{
		if(pthread_join(p_th[i], NULL) != 0)
			return (str_err(ERR_JOIN, 3));
		i++;
	}
	return (0);
}
int	destThr(unsigned long long philoNbr, pthread_t *forks)
{
	unsigned int i;

	i = 0;
	while (i < philoNbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
int main(int argc, char *argv[])
{
	unsigned int i;
	pthread_t   p_th[2000];
	unsigned long long ltaArr[2000];
	pthread_mutex_t forks[2000];
	pthread_mutex_t message;
	t_philo philos[2000];
	t_philo deathStr;
	pthread_t deathThread;
	bool running;
	unsigned long long philoNbr;
	unsigned long long timeToDie;
	unsigned long long timeToEat;
	unsigned long long timeToSleep;
	unsigned long long mustEatNbr;

	if ((argc < 5 || argc > 6) && ft_atoi(argv[1]) < 2)
		return (str_err(ERR_ARG, 1));
	philoNbr = ft_atoi(argv[1]);
	
	timeToDie = ft_atoi(argv[2]);
	timeToEat = ft_atoi(argv[3]);
	timeToSleep = ft_atoi(argv[4]);
	if (argc == 6)
		mustEatNbr = ft_atoi(argv[5]);
	else
		mustEatNbr = -1;
	running = true;
	i = 0;
	while (i < philoNbr)
	{
		ltaArr[i] = getTime();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&message, NULL);
	i = 0;
	while(i < philoNbr)
	{
		philos[i].philoNum = philoNbr;
		philos[i].forks = &forks[0];
		philos[i].ltaArr = &ltaArr[0];
		philos[i].running = &running;
		philos[i].timeToDie = timeToDie;
		philos[i].timeToEat = timeToEat;
		philos[i].timeToSleep = timeToSleep;
		philos[i].mustEatNbr = mustEatNbr;
		philos[i].message = &message;
		philos[i].pId = i;
		if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
		{
			return(str_err(ERR_CRT, 1));
		}
		i++;
	}
	deathStr.philoNum = philoNbr;
	deathStr.ltaArr = &ltaArr[0];
	deathStr.running = &running;
	deathStr.timeToDie = timeToDie;
	deathStr.timeToEat = timeToEat;
	deathStr.timeToSleep = timeToSleep;
	deathStr.message = &message;
	if (pthread_create(&deathThread, NULL, &detectDeath, &deathStr) != 0)
		return (str_err(ERR_CRT, 1));
	joinThr(philoNbr, p_th);
	if(pthread_join(deathThread, NULL) != 0)
		return (str_err(ERR_JOIN, 1));
	destThr();
	pthread_mutex_destroy(&message);
	return (0);
}

