/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:59:43 by mkhabou           #+#    #+#             */
/*   Updated: 2020/07/21 18:00:04 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_base(char *base)
{
	int	i;
	int	len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		i = len + 1;
		while (base[i])
		{
			if (base[len] == base[i])
				return (0);
			i++;
		}
		len++;
	}
	if (len < 2)
		return (0);
	return (len);
}

int	ft_result(char *base, char *number, int i, int len_base)
{
	int	j;
	int	nbr;

	j = 0;
	nbr = 0;
	while (base[j])
	{
		if (!number[i])
			break ;
		while (number[i] == base[j])
		{
			nbr = nbr * len_base + j;
			i++;
			j = 0;
		}
		j++;
	}
	return (nbr);
}

int	ft_atoi_base(char *number, char *base)
{
	int	i;
	int	neg;
	int	len_base;
	int	first_conversion;

	len_base = ft_len_base(base);
	if (!len_base)
		return (0);
	i = 0;
	while (number[i] == '\t' || number[i] == '\f'
		|| number[i] == ' ' || number[i] == '\n'
		|| number[i] == '\r' || number[i] == '\v')
		i++;
	neg = 1;
	while (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			neg = -neg;
		i++;
	}
	first_conversion = ft_result(base, number, i, len_base);
	return (first_conversion * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	conv_nbr;
	char		*final_nbr;

	conv_nbr = ft_atoi_base(nbr, base_from);
	final_nbr = ft_convert_from_decimal(conv_nbr, base_to, ft_strlen(base_to));
	return (final_nbr);
}
