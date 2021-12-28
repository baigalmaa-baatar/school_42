/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_are_detached_threads.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:15:11 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:15:12 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

#define THREAD_NUMBER   2

void    *routine(void *arg)
{
    sleep(1);
    printf("Finished execution\n");
    return (arg);
}

int main(void)
{
    int i = 0;
    pthread_t   p[THREAD_NUMBER];
    pthread_attr_t  detached_thread;

    pthread_attr_init(&detached_thread);
    pthread_attr_setdetachstate(&detached_thread, PTHREAD_CREATE_DETACHED);

    while (i < THREAD_NUMBER)
    {
        if (pthread_create(&p[i], &detached_thread, &routine, NULL) != 0)
            perror("Failed to create thread");
        pthread_detach(p[i]);
        i++;
    }
    // i = 0;
    // while (i < THREAD_NUMBER)
    // {
    //     if (pthread_join(p[i], NULL) != 0)
    //         perror("Failed to join thread");
    //     i++;
    // }
    pthread_attr_destroy(&detached_thread);
    pthread_exit(0);
}
