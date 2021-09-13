/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:15 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/13 15:32:49 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_p(struct s_format *format, va_list a_list)
{
	char buff[100];
	int max;
	int i;
	unsigned long long nbr;

	memset(buff, ' ', 100 * sizeof(char));
	buff[99] = '\0';
	i = 98;
	max = 0;
	nbr = va_arg(a_list, unsigned long long);
	if (!nbr)
	{	
		ft_putstr(&buff[102 - format->width]);
		ft_putstr("0x0");
		return (ft_max(format->width, 3));
	}
	else
	{
		while(nbr > 0)
		{
			buff[i] = "0123456789abcdef"[nbr % 16];
			nbr /= 16;
			i--;
		}
		buff[i] = 'x';
		buff[i - 1] = '0';
		max = ft_max(format->width, 101 - i);
		if (format->width >= 101 - i)
			max++;
		ft_putstr(&buff[100 - max]);
	}
	return (max - 1);
}
