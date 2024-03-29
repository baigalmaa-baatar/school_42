/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/06 19:55:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int nbr_ui;

	if (nbr < 0)
	{	
		write(fd, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_ui = (unsigned int)nbr;

    if (nbr_ui > 9)
    {
        ft_putnbr_fd(nbr_ui / 10, fd);
    }
    ft_putchar_fd(nbr_ui % 10 + '0', fd);
}

int main()
{
	int i = (-2147483647 - 1);
	// int i = (-21 - 1);
	ft_putnbr_fd(i, 1);

	return(0);
}
