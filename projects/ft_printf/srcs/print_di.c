/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:01 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/13 15:32:03 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_di(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	int i;
	int max;
	int len;
	int negative;
	long nbr;
	int num_chars;
	int flag_prec;

	nbr = va_arg(a_list, int);
	negative = 0;
	num_chars = 0;
	flag_prec = 0;
	len = ft_length_nbr(nbr);
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
		if(flag_prec)
		{
			max = ft_max(format->width, precision);
			ft_putstr(&buff[100 - 1 - max]);
			return (max);
		}
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
			buff[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 3 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 3 - max]);
		}
		else if(precision > len)
		{	
			memset(buff + (100 - 2 - precision), '-', sizeof(char));
		}
		else
		{
			memset(buff + (100 - 2 - len), '-', sizeof(char));
		}
	}
	if (negative)
	{
		if  (max == len)
		{
			ft_putstr(&buff[100 - 2 - max]);

		}
		else if (len > precision)
		{
			ft_putstr(&buff[100 - 1 - max]);
			max--;
		}
		else
			ft_putstr(&buff[100 - 1 - max]);
		return (max + 1);
	}
	else
		ft_putstr(&buff[100 - 1 - max]);
	return (max);
}
