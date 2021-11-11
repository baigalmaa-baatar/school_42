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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void send_char(int pid, int nbr)
{
	int i;
	int array[8];

	// printf("nbr is : %d\n", nbr);
	i = 0;
	while (i < 8)
	{
		if (nbr % 2)
			array[i] = 1;
		else
			array[i] = 0;
		nbr /= 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		// printf("array %d\n", array[i]);
		if (array[i] % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		i--;
	}
}

void send_str(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		{
			send_char(pid, str[i]);
			i++;
		}
	send_char(pid, '\n');
}

void	client_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signum;
	ft_putstr("Signal received!\n");
}
int main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = client_handler;

	if ((sigaction(SIGUSR2, &sa, NULL)) == -1)
		error("Sigaction error occured!\n");
	if (argc == 3)
		send_str(atoi(argv[1]), argv[2]);
	else
		error("Arguments error occured!\n");
	return (0);
}