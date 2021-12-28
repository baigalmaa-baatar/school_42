/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value_from_thread.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:59:03 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/27 17:59:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_thread.h"

void    *roll_dice(void *vararg)
{
    int *val;
    
    (void)vararg;
    val = malloc (sizeof(int *));
    *val = (rand() % 6) + 1;
    printf("thread address : %p\n", val);
    return ((void *)val);
}

int main(void)
{
    int *res;
    pthread_t p;

    srand(time(NULL));

    if (pthread_create(&p, NULL, &roll_dice, NULL) != 0)
    {
        perror("The error occured creating thread\n");
        return (1);
    }
    if (pthread_join(p, (void **)&res) != 0)
    {
        perror("The error occured joining thread\n");
        return (2);
    }
    printf("The value is %d\n", *res);
    printf("thread address : %p\n", res);
    free(res);
    return (0);
}