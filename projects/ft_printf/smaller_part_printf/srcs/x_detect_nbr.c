/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_detect_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:33:28 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:24:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	x_detect_nbr(unsigned int *nbr, struct s_format *format,
char *buff, int *i)
{
	if (!*nbr)
	{
		if (format->flag_prec)
			buff[*i] = '\0';
		else
			buff[*i] = '0';
	}
	else
		putnbr_base(nbr, format, buff, i);
}
