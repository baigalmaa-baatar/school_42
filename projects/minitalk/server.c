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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr(int numbr)
{
	if (numbr < -9 || numbr > 9)
		ft_putnbr(numbr / 10);
	if (numbr < 0)
	{
		if (numbr >= -9 && numbr <= 9)
		{
			ft_putchar('-');
		}
		ft_putchar('0' - (numbr % 10));
	}
	else
	{
		ft_putchar('0' + (numbr % 10));
	}
}

size_t	ft_strlen(const	char	*str)
{
	size_t	len;

	len = 0;
	if (str[0] == '\0')
		return (len);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_print_str(char *str)
{
	ft_putstr(str);
	free(str);
	return (0);
}

char *one_char(char c)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (1 + 1));
	if (!res)
		return (0);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_char_join(char *s1, char c)
{
	char			*res;
	size_t			i;

	if (!c)
		return (0);
	if (!s1)
		return (one_char(c));
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!res)
	{
		free(s1);
		return (0);
	}
	i = 0;
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	return (res);
}

void handle_sigusr(int sig, siginfo_t *siginfo, void *void_var)
{
	static unsigned int cntr = 0;
	static char *str = 0;
	static char	c = 0xFF;

	(void)void_var;
	if (sig == SIGUSR1)
		c ^= 0x80 >> cntr;
	else if (sig == SIGUSR2)
		c |= 0x80 >> cntr;
	if (++cntr == 8)
	{
		if(c)
			str = ft_char_join(str, c);
		else
		{
			str = ft_print_str(str);
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
			{
				ft_putstr("Error signal\n");
				exit(EXIT_FAILURE);
			}
		}
		cntr = 0;
		c = 0xFF;
	}
}

int main(void)
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	write(1, "PID is : ", 9);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}