/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:17:41 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/05 17:58:54 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(unsigned long long nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		if (fd >= 0)
			ft_putchar_fd(nbr + 48, fd);
	}
}

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	res;
	int					neg;

	res = 0;
	neg = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res > LLONG_MAX && neg == 1)
		return (-1);
	if (res > LLONG_MAX && neg == -1)
		return (0);
	return (res * neg);
}

unsigned long long	get_time(void)
{
	struct timeval		tv;
	unsigned long long	milliseconds_since_epoch;

	gettimeofday (&tv, NULL);
	milliseconds_since_epoch = (unsigned long long)(tv.tv_sec)*1000
		+ (unsigned long long)(tv.tv_usec) / 1000;
	return (milliseconds_since_epoch);
}
