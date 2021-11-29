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
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    int x = 2;
    int pid = fork();
    if (pid == -1)
    {
        return (1);
    }
    if (pid == 0)
        x++;
    sleep(2);
    printf("Value of x is  %d\n", x);
    printf("Process ID %d\n", getpid());
    if (pid != 0)
    {
        wait(0);
    }        
    return (0);
}
