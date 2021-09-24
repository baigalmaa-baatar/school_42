/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:15 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/24 16:11:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	p_not_null(char *buff, unsigned long long *nbr)
{
	int	i;
	int	max;

	i = 98;
	max = 0;
	while (*nbr > 0)
	{
		buff[i] = "0123456789abcdef"[*nbr % 16];
		*nbr /= 16;
		i--;
	}
	buff[i] = 'x';
	buff[i - 1] = '0';
	max = 101 - i;
	ft_putstr(&buff[100 - max]);
	return (max - 1);
}

int	print_p(va_list a_list)
{
	char				buff[100];
	unsigned long long	nbr;

	memset (buff, ' ', 100 * sizeof(char));
	buff[99] = '\0';
	nbr = va_arg(a_list, unsigned long long);
	if (!nbr)
	{
		ft_putstr("0x0");
		return (3);
	}
	else
		return (p_not_null(buff, &nbr));
}
