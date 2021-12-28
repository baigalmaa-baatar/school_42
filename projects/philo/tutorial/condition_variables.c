/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:36:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 17:36:42 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

int fuel = 0;
pthread_mutex_t mutex_fuel;
pthread_cond_t  cond_fuel;

void    *fuel_filling(void *arg)
{
    int i = 0;
    while (i < 5)
    {
        pthread_mutex_lock(&mutex_fuel);
        fuel += 15;
        printf("Filling the fuel %d\n", fuel);
        pthread_mutex_unlock(&mutex_fuel);
        sleep(1);
        i++;
    }
    return (arg);
}

void    *car(void *arg)
{
    pthread_mutex_lock(&mutex_fuel);
    while (fuel < 40)
    {
        printf("No fuel. Waiting ...\n");
        pthread_cond_wait(&cond_fuel, &mutex_fuel);
        
    }
    fuel -= 40;
    printf("Got fuel. Now left %d\n", fuel);
    pthread_mutex_unlock(&mutex_fuel);
    return (arg);
}

int main(void)
{
    int i = 0;
    pthread_t p[2];

    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_cond_init(&cond_fuel, NULL);
    while (i < 2)
    {
        if (i == 0)
        {   
            if (pthread_create(&p[i], NULL, &car, NULL) != 0)
                perror("Failed to create thread!");
                
        }
        else
        {
            if (pthread_create(&p[i], NULL, &fuel_filling, NULL) != 0)
                perror("Failed to create thread!");
        }
        i++;
    }
    i = 0;
    while (i < 2)
    {
        if (pthread_join(p[i], NULL) != 0)
            perror("Failed to join thread!");
        i++;
    }
    pthread_mutex_destroy(&mutex_fuel);
    pthread_cond_destroy(&cond_fuel);
    return (0);
}

