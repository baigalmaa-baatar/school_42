/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:45:47 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/10 13:30:26 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;
	char	neg;

	neg = '-';
	nbr = 0;
	if (n >= 0 && n <= 9)
	{
		nbr = n + '0';
		ft_putchar_fd(nbr, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		nbr = (n % 10) + '0';
		ft_putchar_fd(nbr, fd);
	}
	else if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		ft_putchar_fd(neg, fd);
		ft_putnbr_fd((n * -1), fd);
	}
}
