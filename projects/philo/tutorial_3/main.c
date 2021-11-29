/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:14:48 by bbaatar           #+#    #+#             */
/*   Updated: 2021/11/29 12:14:50 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t     mutex;

void    *routine(void   *vargarp)
{
    int i = 0;
    
    while (i < 10000000)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        i++;
    }
}

int main(void)
{
    pthread_t  p[4];
    int i = 0;
    
    pthread_mutex_init(&mutex, NULL);
    while (i < 4)
    {
        if (pthread_create(&p[i], NULL, routine, NULL))
        {
            perror("Failed to create thread");
            return (1);
        }
        printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while ( i < 4)
    {
        if (pthread_join(p[i], NULL))
            return (1);
        printf("Thread %d has finished\n", i);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails %d\n", mails);
    return (0);

}
