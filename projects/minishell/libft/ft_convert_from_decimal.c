/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_from_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:24:07 by mkhabou           #+#    #+#             */
/*   Updated: 2021/06/28 14:24:10 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rv_tab(char *nbr)
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

char	*ft_convert_from_decimal(long long number, char *base_to, int base_len)
{
	int		i;
	int		neg;
	char	*converted_number;

	i = 0;
	neg = 0;
	converted_number = ft_strfill('\0', 65);
	if (!converted_number)
		return (NULL);
	if (number < 0)
	{
		converted_number[i++] = '-';
		number = number * -1;
		neg = 1;
	}
	while ((number / base_len) >= 1)
	{
		converted_number[i] = base_to[number % base_len];
		number = number / base_len;
		i++;
	}
	converted_number[i] = base_to[number];
	ft_rv_tab(&converted_number[neg]);
	return (converted_number);
}
