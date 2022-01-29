/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:34:37 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/15 13:07:09 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	long	ft_abs(long long n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	ft_len(long long n)
{
	int	len;
	int	count;

	len = 1;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while ((ft_abs(n) / len) > 0)
	{
		count++;
		len = len * 10;
	}
	return (count);
}

static void	ft_rv_tab(char *nbr)
{
	int		i;
	int		l2;
	int		l;
	char	a;

	l = ft_strlen(nbr);
	l2 = l / 2;
	i = 0;
	while (i < l2)
	{
		a = nbr[i];
		nbr[i] = nbr[l - 1];
		nbr[l - 1] = a;
		i++;
		l--;
	}
}

static void	ft_rv_nbr(long long n, char *nbr)
{
	int			j;
	long long	abs_n;

	abs_n = ft_abs(n);
	j = 0;
	while (abs_n > 9)
	{
		nbr[j] = (abs_n % 10) + 48;
		abs_n = abs_n / 10;
		j++;
	}
	nbr[j] = abs_n + 48;
	nbr[j + 1] = '\0';
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			i;
	long long	nb;

	nb = n;
	nbr = malloc(sizeof(char) * (ft_len(nb) + 1));
	if (nbr == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		nbr[0] = '-';
		i++;
	}
	ft_rv_nbr(nb, &nbr[i]);
	ft_rv_tab(&nbr[i]);
	return (nbr);
}
