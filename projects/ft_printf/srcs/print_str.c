/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:30 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/13 15:32:31 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_str(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	const char *str;
	const char *str_buff;
	int i;
	int max;
	int len;
	int flag_prec;
	int num_chars;

	flag_prec = 0;
	num_chars = 0;
	str_buff = va_arg(a_list, const char *);
	if (!str_buff)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str_buff);
	memset(buff, ' ', 100 * sizeof(char));
	buff[99] = '\0';
	i = 98;
	if (format->precision == -1)
		precision = 0;
	else
	{
		flag_prec = 1;
		precision = format->precision;
	}
	len = ft_strlen(str);
	max = ft_max(format->width, len);
	if (flag_prec && !precision)
	{
		if (!format->width)
			ft_putstr("");
		else
			ft_putstr(&buff[100 - format->width - 1]);
	}
	else
	{
		if (precision > 0 && precision < len)
		{
			max = ft_max(format->width, precision);
			len = precision;
		}
		len--;
		while (len >= 0)
		{
			buff[i] = str[len];
			len--;
			i--;
		}
		ft_putstr(&buff[100 - max - 1]);
		num_chars = max;
	}
	free((char *)str);
	if(!str)
		return (0);
	return (num_chars);
}
