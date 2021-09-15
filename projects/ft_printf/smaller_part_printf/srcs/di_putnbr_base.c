/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:41:45 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:23:15 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	di_putnbr_base(long *nbr, struct s_format *format,
char *buff, int *i)
{
	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		format->negative = 1;
	}
	while (*nbr > 0)
	{
		buff[*i] = format->base[*nbr % format->base_nbr];
		*nbr /= format->base_nbr;
		(*i)--;
	}
}
