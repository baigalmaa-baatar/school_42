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

int	print_di(va_list a_list)
{
	long	nbr;

	nbr = va_arg(a_list, int);
	if (nbr < 0)
	{
		return (write(1, "-", 1) + putnbr_base(-((long long)nbr), 10,
				"0123456789"));
	}
	else
	{
		return (putnbr_base(nbr, 10, "0123456789"));
	}
}
