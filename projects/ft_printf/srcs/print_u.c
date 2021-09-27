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

int	print_u(va_list a_list)
{
	unsigned long long	nbr;

	nbr = va_arg(a_list, unsigned int);
	return (putnbr_base(nbr, 10, "0123456789"));
}
