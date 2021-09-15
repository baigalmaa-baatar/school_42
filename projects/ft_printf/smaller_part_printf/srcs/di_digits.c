/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:33:47 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:20:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_min_char(struct s_format *format, int *max, int *len, char *buff)
{
	if (format->negative)
	{
		if (format->precision == *max && format->precision > *len)
		{
			memset(buff + (97 - *max), '-', sizeof(char));
			ft_putchar(buff[97 - *max]);
		}
		else if (format->precision > *len)
			memset(buff + (98 - format->precision), '-', sizeof(char));
		else
			memset(buff + (98 - *len), '-', sizeof(char));
	}
}

int	di_digits(struct s_format *format, int *max, int *len, char *buff)
{
	put_min_char(format, max, len, buff);
	if (format->negative)
	{
		if (*max == *len)
			ft_putstr(&buff[98 - *max]);
		else if (*len > format->precision)
		{
			ft_putstr(&buff[99 - *max]);
			(*max)--;
		}
		else
			ft_putstr(&buff[99 - *max]);
		return (*max + 1);
	}
	else
		ft_putstr(&buff[99 - *max]);
	return (*max);
}
