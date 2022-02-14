/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_putstrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:47 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/12 20:49:51 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	special_putchar(char c, int fd)
{
	if (write(1, &c, fd) == -1)
		return (0);
	return (1);
}

int	special_putendl(char *s, int fd)
{
	int		i;
	char	n;

	i = 0;
	n = '\n';
	if (s)
	{
		while (s[i])
		{
			if (write(fd, &s[i], 1) == -1)
				return (0);
			i++;
		}
	}
	if (write(fd, &n, 1) == -1)
		return (0);
	return (1);
}

int	special_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (write(fd, &s[i], 1) == -1)
				return (0);
			i++;
		}
	}
	return (1);
}

int	special_mtp_putstr(char *s1, char *s2, char *s3, int fd)
{
	if (s1)
	{
		if (!special_putstr(s1, fd))
			return (0);
	}
	if (s2)
	{
		if (!special_putstr(s2, fd))
			return (0);
	}
	if (s3)
	{
		if (!special_putstr(s3, fd))
			return (0);
	}
	return (1);
}
