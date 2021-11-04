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

void handle_sigtstp(int sig)
{
	write (STDOUT_FILENO, "You can't terminate!\n", 21);
	(void)sig;
}

void handle_sigcont(int sig)
{
	write (STDOUT_FILENO, "Input number :\n", 15);
	fflush(stdout);
	(void)sig;
}

int main(int argc, char *argv[])
{
	int x;
	struct sigaction sa;

	sa.sa_handler = &handle_sigtstp;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGCONT, &sa, NULL);
	
	// signal(SIGTSTP, &handle_sigtstp);

	(void)argc;
	(void)argv;
	printf("Insert the number : \n");
	scanf("%d", &x);
	printf("Result of %d * 5 is %d\n", x, x * 5);
	return (0);
}