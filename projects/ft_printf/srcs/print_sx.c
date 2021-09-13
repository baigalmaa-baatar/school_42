/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:31:49 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/13 15:31:50 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_sx(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned int nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	max = 0;
	nbr = va_arg(a_list, int);
	len = ft_length_X((unsigned int)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - 1 - precision), '0', precision * sizeof(char));
	buff[99] = '\0';
	i = 98;
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = "0123456789abcdef"[nbr % 16];
			nbr /= 16;
			i--;
		}
	}
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 2 - max]);
	}
	else
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	return (max);
}
