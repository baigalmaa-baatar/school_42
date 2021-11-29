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

int x = 2;

void    *routing(void   *vargarp)
{
    x++;
    sleep(2);
    printf("Value of x is  %d\n", x);
}

void    *routing2(void   *vargarp)
{
    sleep(2);
    printf("Value of x is  %d\n", x);
}

int main(void)
{
    pthread_t  t1, t2;

    if (pthread_create(&t1, NULL, routing, NULL))
        return (1);
    if (pthread_create(&t2, NULL, routing2, NULL))
        return (1);
    if (pthread_join(t1, NULL))
        return (1);
    if (pthread_join(t2, NULL))
        return (1);

    return (0);

}
