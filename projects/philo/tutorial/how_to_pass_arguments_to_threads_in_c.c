/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_pass_arguments_to_threads_in_c.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:59:03 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/27 17:59:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

int primes[10] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23};

void    *get_prime_nbr(void *arg)
{
    int index;

    sleep(1);
    index = *(int *)arg;
    printf("******************** prime number : %d\n", *(int *)arg);
    return ((void *)&primes[index]);
}

int main(void)
{
    int i = 0;
    int *res;
    int *val_i;

    pthread_t p[10];

    while (i < 10)
    {
        val_i = malloc(sizeof(int));
        *val_i = i;
        if (pthread_create(&p[i], NULL, &get_prime_nbr, val_i) != 0)
        {   
            perror("The error occured creating thread\n");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < 10)  
    {
        if (pthread_join(p[i], (void **)&res) != 0)
        {
            perror("The error occured joining thread\n");
            return (2);
        }
        printf("The prime number is %d\n", *res);
        i++;
    }
    free(res);
    free(val_i);
    return (0);
}