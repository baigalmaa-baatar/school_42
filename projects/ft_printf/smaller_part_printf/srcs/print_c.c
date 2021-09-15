/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/14 16:08:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_c(struct s_format *format, va_list a_list)
{
	char	buff[100];
	char	c;
	int		num_chars;

	num_chars = 0;
	memset (buff, ' ', 100 * sizeof(char));
	buff[99] = '\0';
	c = (char) va_arg(a_list, int);
	if (!c)
	{
		num_chars = ft_max(format->width, 1);
		ft_putstr(&buff[100 - num_chars]);
		ft_putchar(0);
		return (num_chars);
	}
	buff[98] = c;
	num_chars = ft_max(format->width, 1);
	ft_putstr(&buff[99 - num_chars]);
	return (num_chars);
}
