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

unsigned long long getTime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	unsigned long long millisecondsSinceEpoch = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
	return (millisecondsSinceEpoch);
}

void    *routine(void *arg)
{
	pthread_mutex_t *leftFork;
    pthread_mutex_t *rightFork;
	t_philo *philos;

	philos = (t_philo *)arg;
	// printf("Thread has created!!!: %d\n", philos->pId);
    while (1)
    {
		if (!(*philos->running))
			break;
		leftFork = &philos->forks[philos->pId];
        rightFork = &philos->forks[(philos->pId + 1) % philos->philoNum];
        if(philos->pId % 2)
		{
			pthread_mutex_lock(leftFork);
        	pthread_mutex_lock(rightFork);
			if (!(*philos->running))
				break;
        	printf("%llu %d has taken a fork\n", getTime(), philos->pId);
		}
		else
		{
			pthread_mutex_lock(rightFork);
			pthread_mutex_lock(leftFork);
			if (!(*philos->running))
				break;
        	printf("%llu %d has taken a fork\n", getTime(), philos->pId);
		}
		philos->ltaArr[philos->pId] = getTime();
		if (!(*philos->running))
			break;
        printf("%llu %d is eating\n", getTime(), philos->pId);
		// printf("inputval time to eat : %llu\n", philos->timeToEat);
        usleep(philos->timeToEat * 1000);
        pthread_mutex_unlock(leftFork);
        pthread_mutex_unlock(rightFork);
		if (!(*philos->running))
			break;
        printf("%llu %d is sleeping\n", getTime(), philos->pId);
        usleep(philos->timeToSleep * 1000);
		if (!(*philos->running))
			break;
        printf("%llu %d is thinking\n", getTime(), philos->pId);
    }
    return (NULL);
}

bool	init_philos(t_philo *philos, int philoNum)
{
	philos->philoNum = philoNum;
	philos->pId = 0;
	return (true);
}

void    *detectDeath(void *arg)
{
	unsigned int i;
	unsigned long long delatLTA;
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
    	while(i < philos->philoNum)
    	{
			delatLTA = getTime() - philos->ltaArr[i];
			// printf("deltaLTA: %llu\n", delatLTA);
        	if (delatLTA >= philos->timeToDie)
			{
	        	printf("%llu %d died\n", getTime(), i);
				*(philos->running) = false;
				return (NULL);
			}
			i++;
    	}
		usleep(5000);
		// printf("enen deer neg yum hevleed uz dee\n");
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
    unsigned int i;
    pthread_t   p_th[100];
	unsigned long long ltaArr[100];
	pthread_mutex_t forks[100];
	t_philo philos[100];
	t_philo deathStr;
	pthread_t deathThread;
	bool running;
	unsigned long long inputVal[5];
	unsigned long long philoNbr;
	unsigned long long timeToDie;
	unsigned long long timeToEat;
	unsigned long long timeToSleep;

	if (argc < 5 || argc > 6)
		str_err(ERR_ARG, 1);
	// philoNbr = get_args(argv, &inputVal);
	philoNbr = get_args(argv, inputVal);
	timeToDie = inputVal[1];
	timeToEat = inputVal[2];
	timeToSleep = inputVal[3];
	printf("Number of philo: %llu\n", philoNbr);
	printf("Time to die : %llu\n", timeToDie);
	printf("Time to eat : %llu\n", timeToEat);
	printf("Time to sleep : %llu\n", timeToSleep);
	if (!philoNbr)
		str_err(ERR_ARG, 1);
	running = true;
	i = 0;
	while (i < philoNbr)
	{
		ltaArr[i] = getTime();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	// pthread_mutex_init(&deathlock, NULL);
    i = 0;
    while(i < philoNbr)
    {
		philos[i].philoNum = philoNbr;
		philos[i].forks = &forks[0];
		philos[i].ltaArr = &ltaArr[0];
		philos[i].running = &running;
		philos[i].timeToEat = timeToEat;
		philos[i].timeToSleep = timeToSleep;
		philos[i].pId = i;
        if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
            str_err(ERR_CRT, 1);
		i++;
		// usleep(10000);
    }
	deathStr.philoNum = philoNbr;
    deathStr.ltaArr = &ltaArr[0];
	deathStr.running = &running;
	deathStr.timeToDie = timeToDie;
	if (pthread_create(&deathThread, NULL, &detectDeath, &deathStr) != 0)
        str_err(ERR_CRT, 1);
	i = 0;
    while(i < philoNbr)
    {
        if (pthread_join(p_th[i], NULL) != 0)
            str_err(ERR_JOIN, 1);
        i += 1;
    }
    // i = 0;
    // while(i < 2)
    // {
    //     if (pthread_detach(p[i]) != 0)
    //         str_err(ERR_DET, 1);
    //     i += 2;
    // }
    i = 0;
    while (i < philoNbr)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    i = 0;
    while (i < philoNbr)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
	// free(philos);
    return (0);
}
