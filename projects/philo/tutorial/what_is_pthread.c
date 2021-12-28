/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_pthread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:01:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:01:39 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

#define THREAD_NUM  2

void    *routine(void   *arg)
{
    pthread_t   p = pthread_self();

    printf("%ld\n", p);
    return (arg);
}

int main(void)
{
    int i = 0;
    pthread_t   p[THREAD_NUM];

    while (i < THREAD_NUM)
    {
        if (pthread_create(&p[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
        printf("%lu\n", p[i]);
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if (pthread_join(p[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    return (0);
}
