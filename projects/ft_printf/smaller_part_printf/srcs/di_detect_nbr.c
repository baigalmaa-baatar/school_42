/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_detect_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:33:28 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:22:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	di_detect_nbr(long *nbr, struct s_format *format,
	char *buff, int *i)
{
	int	char_nbr;

	char_nbr = 0;
	if (!*nbr)
	{
		if (format->flag_prec)
		{
			char_nbr = ft_max(format->width, format->precision);
			ft_putstr(&buff[99 - char_nbr]);
			return (char_nbr);
		}
		else
			buff[*i] = '0';
	}
	else
	{
		di_putnbr_base(nbr, format, buff, i);
	}
	return (char_nbr);
}
