/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:33:28 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:24:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void str_null(struct s_format *format, char *buff)
{
	if (!format->width)
		ft_putstr("");
	else
		ft_putstr(&buff[99 - format->width]);
}

int	str_detect(const char *str, struct s_format *format, char *buff)
{
	int i;
	int max;
	int len;

	buff[99] = '\0';
	i = 98;
	len = ft_strlen(str);
	max = ft_max(format->width, len);
	if (format->flag_prec && !format->precision)
		str_null(format, buff);
	else
	{
		if (format->precision > 0 && format->precision < len)
		{
			max = ft_max(format->width, format->precision);
			len = format->precision;
		}
		len--;
		while (len >= 0)
		{
			buff[i--] = str[len--];
		}
		ft_putstr(&buff[99 - max]);
	}
	return (max);
}