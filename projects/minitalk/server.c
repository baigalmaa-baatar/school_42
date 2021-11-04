/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:40:16 by bbaatar           #+#    #+#             */
/*   Updated: 2021/11/04 14:40:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void handler(int num)
{
	write(STDOUT_FILENO, "I won't die!\n", 13);
	(void)num;
}

void sig_handler(int num)
{
	write(STDOUT_FILENO, "Seg fault!\n", 10);
	(void)num;
}

int main(void)
{
	int *p = NULL;
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	signal(SIGKILL, handler);
	signal(SIGSEGV, sig_handler);

	*p = 45;//segfault
	while (1)
	{
		printf("pid is  : %d\n", getpid());
	}
	sleep(100);
}