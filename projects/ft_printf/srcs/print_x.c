/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:31:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/20 16:17:03 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_x(va_list a_list)
{
	unsigned long long	nbr;

	nbr = va_arg(a_list, unsigned int);
	return (putnbr_base(nbr, 16, "0123456789ABCDEF"));
}
