/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:41:45 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/16 00:24:14 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	putnbr_base_without_zero(unsigned long long nbr, unsigned int base_nbr,
char *base)
{
	int	result;

	if (nbr == 0)
		return (0);
	result = 0;
	result += putnbr_base_without_zero(nbr / base_nbr, base_nbr, base);
	result += write(1, &base[nbr % base_nbr], 1);
	return (result);
}

int	putnbr_base(unsigned long long nbr, unsigned int base_nbr, char *base)
{
	if (nbr == 0)
		return (write(1, &base[0], 1));
	return (putnbr_base_without_zero(nbr, base_nbr, base));
}
