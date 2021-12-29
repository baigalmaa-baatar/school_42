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

#define PHILOSOPHERS_NUMBER 4
#define TIME_TO_DIE 5 //500ms
#define TIME_TO_EAT 2 //200ms
#define TIME_TO_SLEEP 2 //200ms

pthread_mutex_t forks[PHILOSOPHERS_NUMBER];


int str_err(char *str, int ret)
{
    write(1, str, ft_strlen(str));
    return (ret);
}

void    *routine(void   *arg)
{
    int philo;

    philo = *(int *)arg;

    pthread_mutex_t leftFork;
    pthread_mutex_t rightFork;

    pthread_mutex_init(&leftFork, NULL);
    pthread_mutex_init(&rightFork, NULL);
    while (1)
    {
        leftFork = forks[philo];
        rightFork = forks[(philo + 1) % PHILOSOPHERS_NUMBER];
        pthread_mutex_lock(&leftFork);
        printf("timestamp_in_ms %d has taken a left fork\n", philo);
        pthread_mutex_lock(&rightFork);
        printf("timestamp_in_ms %d has taken a right fork\n", philo);
        printf("timestamp_in_ms %d is eating\n", philo);
        sleep(TIME_TO_EAT);
        pthread_mutex_unlock(&leftFork);
        pthread_mutex_unlock(&rightFork);
        printf("timestamp_in_ms %d is sleeping\n", philo);
        sleep(TIME_TO_SLEEP);
        printf("timestamp_in_ms %d is thinking\n", philo);
    }
        pthread_mutex_destroy(&leftFork);
        pthread_mutex_destroy(&rightFork);
    return (arg);
}

int main(void)
{
    int i;
    int *philo_num;
    pthread_t   philo[PHILOSOPHERS_NUMBER];

    i = 0;
    while (i < PHILOSOPHERS_NUMBER)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    i = 0;
    while(i < PHILOSOPHERS_NUMBER)
    {
        philo_num = malloc(sizeof(int));
        *philo_num = i;
        if (pthread_create(&philo[i], NULL, &routine, philo_num) != 0)
            str_err(ERR_CRT, 1);
        free(philo_num);
        i += 1;
    }
    i = 0;
    while(i < PHILOSOPHERS_NUMBER)
    {
        if (pthread_join(philo[i], NULL) != 0)
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
    while (i < PHILOSOPHERS_NUMBER)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    i = 0;
    while (i < PHILOSOPHERS_NUMBER)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    return (0);
}
