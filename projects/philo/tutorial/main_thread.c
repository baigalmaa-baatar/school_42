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

#include "my_thread.h"

int x = 2;

void    *routing(void   *vargarp)
{
    x++;
    sleep(2);
    printf("Value of x is  %d\n", x);
    return (vargarp);
}

void    *routing2(void   *vargarp)
{
    sleep(2);
    printf("Value of x is  %d\n", x);
    return (vargarp);
}

int main(void)
{
    pthread_t  p1, p2;

    if (pthread_create(&p1, NULL, routing, NULL))
        return (1);
    if (pthread_create(&p2, NULL, routing2, NULL))
        return (1);
    if (pthread_join(p1, NULL))
        return (1);
    if (pthread_join(p2, NULL))
        return (1);
    return (0);
}
