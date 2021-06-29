/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:54:35 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/18 12:54:39 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	unsigned int	nbr_ui;

	if (nbr < 0)
	{	
		write (1, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_ui = (unsigned int)nbr;
	if (nbr_ui > 9)
	{
		ft_putnbr (nbr_ui / 10);
	}
	ft_putchar(nbr_ui % 10 + '0');
}
