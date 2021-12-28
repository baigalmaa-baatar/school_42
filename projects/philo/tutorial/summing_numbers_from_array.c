/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practical_example_for_using_threads.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:47:32 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/27 19:47:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    int i = 0;
    int index;
    int sum = 0;

    index = *(int *)arg;
    while (i < 5)
    {
        sum += primes[index + i];
        i++;
    }
    *(int *)arg = sum;
    return (arg);
}

int main(void)
{
    int i = 0;
    int globalSum;
    int *res;
    int *val_i;
    pthread_t p[2];

    while (i < 2)
    {
        val_i = malloc(sizeof(int));
        *val_i = i * 5;
        if (pthread_create(&p[i], NULL, &routine, val_i) != 0) 
        {
            perror ("Failed to create thread\n");
        }
        i++;
    }
    i = 0;
    globalSum = 0;
    while (i < 2)
    {
        if (pthread_join(p[i],(void **)&res) != 0)
        {
            perror ("Failed to create thread\n");
        }
        globalSum += *res;
        free(res);
        i++;
    }
    printf("the sum of array is : %d\n", globalSum);
    return (0);
}