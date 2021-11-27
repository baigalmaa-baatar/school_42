/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:40:16 by bbaatar           #+#    #+#             */
/*   Updated: 2021/11/25 15:55:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_char(int pid, unsigned char nbr)
{
	int	i;
	int	array[8];

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
		if (array[i] % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		i--;
	}
}

void	send_end_sig(int pid)
{
	send_char(pid, '\0');
}

void	send_str(int pid, unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_end_sig(pid);
}

void	client_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signum;
	ft_putstr_fd("Message received!\n", 1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = client_handler;
	if ((sigaction(SIGUSR2, &sa, NULL)) == -1)
		ft_putstr_fd("Sigaction error occured!\n", 1);
	if (argc == 3)
		send_str(ft_atoi(argv[1]), (unsigned char *)argv[2]);
	else
		ft_putstr_fd("Arguments error occured!\n", 1);
	return (0);
}
