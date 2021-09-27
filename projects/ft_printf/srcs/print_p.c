/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:15 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/24 16:11:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_p(va_list a_list)
{
	unsigned long long	nbr;

	nbr = va_arg(a_list, unsigned long long);
	return (write(1, "0x", 2) + putnbr_base(nbr, 16, "0123456789abcdef"));
}
