/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_digits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:33:47 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/15 20:33:49 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	x_digits(struct s_format *format, int *max, int *len, char *buff)
{
	if (format->negative)
	{
		if (format->precision == *max && format->precision > *len)
		{
			memset(buff + (98 - *max), '-', sizeof(char));
			ft_putchar(buff[98 - *max]);
		}
		else if (format->precision > *len)
			memset(buff + (99 - format->precision), '-', sizeof(char));
		else
			memset(buff + (99 - *len), '-', sizeof(char));
	}
	if (format->negative && *max == *len)
		ft_putstr(&buff[98 - *max]);
	else
		ft_putstr(&buff[99 - *max]);
}
