/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:15 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/14 16:40:34 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	p_null(struct s_format *format, char *buff)
{
	ft_putstr(&buff[102 - format->width]);
	ft_putstr("0x0");
	return (ft_max(format->width, 3));
}

int	p_not_null(struct s_format *format, char *buff, unsigned long long *nbr)
{
	int	i;
	int	max;

	i = 98;
	max = 0;
	while (*nbr > 0)// ene nbr gedeg pointer g yanzlah heregtei.
	{
		buff[i] = "0123456789abcdef"[*nbr % 16];
		*nbr /= 1;
		i--;
	}
	buff[i] = 'x';
	buff[i - 1] = '0';
	max = ft_max(format->width, 101 - i);
	if (format->width >= 101 - i)
		max++;
	ft_putstr(&buff[100 - max]);
	return (max - 1);
}

int	print_p(struct s_format *format, va_list a_list)
{
	char				buff[100];
	unsigned long long	nbr;

	memset (buff, ' ', 100 * sizeof(char));
	buff[99] = '\0';
	nbr = va_arg(a_list, unsigned long long);
	if (!nbr)
		return (p_null(format, buff));
	else
		return (p_not_null(format, buff, &nbr));
}
