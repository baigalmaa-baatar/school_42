/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:31:55 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/18 22:02:42 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_u(struct s_format *format, va_list a_list)
{
	char				buff[100];
	unsigned long long	nbr;
	int					i;
	int					max;
	int					len;

	max = 0;
	nbr = va_arg(a_list, unsigned int);
	len = ft_length_nbr((unsigned long long)nbr);
	prec_point(format);
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (99 - format->precision), '0',
		format->precision * sizeof(char));
	buff[99] = '\0';
	i = 98;
	x_detect_nbr(&nbr, format, buff, &i);
	max = ft_max(ft_max(format->width, format->precision), len);
	u_digits(format, &max, &len, buff);
	return (max);
}
