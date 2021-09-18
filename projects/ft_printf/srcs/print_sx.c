/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:31:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/18 22:03:02 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_sx(struct s_format *format, va_list a_list)
{
	char				buff[100];
	unsigned long long	nbr;
	int					i;
	int					max;
	int					len;

	nbr = va_arg(a_list, int);
	len = ft_length_x((unsigned int)nbr);
	prec_point(format);
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (99 - format->precision), '0',
		format->precision * sizeof(char));
	buff[99] = '\0';
	i = 98;
	format->base_nbr = 16;
	format->base = ft_strdup("0123456789abcdef");
	x_detect_nbr(&nbr, format, buff, &i);
	max = ft_max(ft_max(format->width, format->precision), len);
	x_digits(format, &max, &len, buff);
	free((char *)format->base);
	return (max);
}
