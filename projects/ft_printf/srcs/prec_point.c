/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:35:59 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/15 20:36:21 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	prec_point(struct s_format *format)
{
	if (format->precision == -1)
	{
		format->flag_prec = 0;
		format->precision = 0;
	}
	else
	{
		format->flag_prec = 1;
	}
}
