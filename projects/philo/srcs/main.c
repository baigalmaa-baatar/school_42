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

#define TIME_TO_DIE 500000 //500ms
#define TIME_TO_EAT 200000 //200ms
#define TIME_TO_SLEEP 200000 //200ms

typedef struct s_philo
{
	unsigned int philoNum;
	int pId;
	unsigned long long *ltaArr;
	pthread_mutex_t *forks;
}	t_philo;

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
	printf("Thread has created!!!: %d\n", philos->pId);
    while (1)
    {
        leftFork = &philos->forks[philos->pId];
        rightFork = &philos->forks[(philos->pId + 1) % philos->philoNum];
        pthread_mutex_lock(leftFork);
        printf("%llu %d has taken a left fork\n", getTime(), philos->pId);
        pthread_mutex_lock(rightFork);
        printf("%llu %d has taken a right fork\n", getTime(), philos->pId);
        printf("%llu %d is eating\n", getTime(), philos->pId);
        usleep(TIME_TO_EAT);
        pthread_mutex_unlock(leftFork);
        pthread_mutex_unlock(rightFork);
        printf("%llu %d is sleeping\n", getTime(), philos->pId);
        usleep(TIME_TO_SLEEP);
        printf("%llu %d is thinking\n", getTime(), philos->pId);
    }
    return (philos);
}

bool	init_philos(t_philo *philos, int philoNum)
{
	int i;

	philos->philoNum = philoNum;
	philos->pId = 0;
	i = 0;

	return (true);
}

int main(int argc, char *argv[])
{
    unsigned int i;

	(void)argc;
	(void)argv;
	unsigned int numbers_of_philos = 4;
    pthread_t   p_th[100];
	unsigned long long ltaArr[100];
	pthread_mutex_t forks[100];
	t_philo philos[100];

	i = 0;
	while (i < numbers_of_philos)
	{
		ltaArr[i] = getTime();
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
    i = 0;
    while(i < numbers_of_philos)
    {
		philos[i].philoNum = numbers_of_philos;
		philos[i].forks = forks;
		philos[i].ltaArr = ltaArr;
		philos[i].pId = i;
		printf("philos[i].pId: %u\n", philos[i].pId);
        if (pthread_create(&p_th[i], NULL, &routine, &philos[i]) != 0)
            str_err(ERR_CRT, 1);
		i += 1;
    }
    i = 0;
    while(i < numbers_of_philos)
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
    while (i < numbers_of_philos)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    i = 0;
    while (i < numbers_of_philos)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
	// free(philos);
    return (0);
}
