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

unsigned int nbr = 0;
unsigned int cntr = 1;

void nbr_gen(int sig)
{
	if (sig == 0)
	{
		nbr = nbr << 1;
	}
	else if (sig == 1)
	{
		nbr = (nbr << 1) + 1;
	}
	if (cntr == 8)
	{
		printf("%c", nbr);
		cntr = 0;
		nbr = 0;
	}
	cntr++;
}

void handle_sigusr(int sig)
{
	if (sig == 30)
	{
		nbr_gen(0);
	}
	else if (sig == 31)
	{
		nbr_gen(1);
	}
}

int main(void)
{
	int pid;

	pid = getpid();
	printf("PID is : %d\n", pid);
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
}