/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:17:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/29 10:17:43 by bbaatar          ###   ########.fr       */
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

unsigned long long getTime(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	unsigned long long millisecondsSinceEpoch = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
	return (millisecondsSinceEpoch);
}

// void preciseSleep(int ms) {
//     struct timespec ts;
//     ts.tv_sec = ms / 1000;
//     ts.tv_nsec = ms % 1000 * 1000000;
//     nanosleep(&ts, &ts);
// }
