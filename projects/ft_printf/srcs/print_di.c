/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:01 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:21:06 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_di(struct s_format *format, va_list a_list)
{
	char	buff[100];
	int		i;
	int		max;
	int		len;
	long	nbr;

	max = 0;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	prec_point(format);
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - 1 - format->precision), '0',
		format->precision * sizeof(char));
	buff[99] = '\0';
	i = 98;
	max = di_detect_nbr(&nbr, format, buff, &i);
	if (max)
		return (max);
	max = ft_max(ft_max(format->width, format->precision), len);
	max = di_digits(format, &max, &len, buff);
	return (max);
}
