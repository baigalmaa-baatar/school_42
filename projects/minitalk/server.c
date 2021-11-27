/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:40:16 by bbaatar           #+#    #+#             */
/*   Updated: 2021/11/25 11:59:57 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char	*ft_print_str(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	return (0);
}

char	*one_char(char c)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (1 + 1));
	if (!res)
		return (0);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_char_join(char *s1, char c)
{
	char	*res;
	size_t	i;

	if (!c)
		return (0);
	if (!s1)
		return (one_char(c));
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(s1);
	return (res);
}

void	handle_sigusr(int sig, siginfo_t *siginfo, void *void_var)
{
	static unsigned int	cntr = 0;
	static char			*str = 0;
	static char			c = 0xFF;

	(void)void_var;
	if (sig == SIGUSR1)
		c ^= 0x80 >> cntr;
	else if (sig == SIGUSR2)
		c |= 0x80 >> cntr;
	if (++cntr == 8)
	{
		if (c)
			str = ft_char_join(str, c);
		else
		{
			str = ft_print_str(str);
			write (1, "\n", 1);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_putstr_fd("Error signal\n", 1);
		}
		cntr = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	sigset_t			blocked_signals;

	sigemptyset(&blocked_signals);
	pid = getpid();
	write (1, "PID is : ", 9);
	ft_putnbr_fd(pid, 1);
	write (1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = blocked_signals;
	sa.sa_handler = NULL;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
