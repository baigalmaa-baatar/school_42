/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 12:16:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int	nbr_ui;

	if (nbr < 0)
	{	
		write (fd, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_ui = (unsigned int)nbr;
	if (nbr_ui > 9)
	{
		ft_putnbr_fd (nbr_ui / 10, fd);
	}
	ft_putchar_fd (nbr_ui % 10 + '0', fd);
}
