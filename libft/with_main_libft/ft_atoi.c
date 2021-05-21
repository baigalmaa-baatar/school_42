/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baigalmaa <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:31:37 by baigalmaa         #+#    #+#             */
/*   Updated: 2021/03/18 13:31:52 by baigalmaa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	size_t i;
	size_t len;
	int res;
	int neg;

	res = 0;
	neg = 1;
	len = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		len++;
		i++;
	}
	if (len > 19)
	{
		if (neg == 1)
			return (-1);
		if (neg == -1)
			return (0);
	}
	while (len > 0)
	{
		res = res * 10 + (str[i - len] - 48);
		len--;
	}
	return (res * neg);
}

int main()
{
	char n[15] = "123";
	int i1;
	i1 = atoi(n);
	int i2;
	i2 = ft_atoi(n);

	printf("Std function : %d\nMy function  : %d\n", i1, i2);

	return (0);
}