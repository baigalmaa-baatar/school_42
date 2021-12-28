/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_between_trylock_and_lock.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:52:09 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 16:52:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

pthread_mutex_t mutex;

void    *routine(void *vararg)
{
    (void)vararg;
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Locked\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Didn't get locked\n");
    }
    return ((void *)1);
}

int main(void)
{
    int i = 0;
    pthread_t p[4];

    pthread_mutex_init(&mutex, NULL);

    while (i < 4)
    {
        if (pthread_create(&p[i], NULL, &routine, NULL) != 0)
            perror("Failed to create a thread");
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (pthread_join(p[i], NULL))
            perror("Failed to join a thread");
        i++;
    }
}
