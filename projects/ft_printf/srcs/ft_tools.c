/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:54:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/13 15:31:29 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_length_nbr(long long nbr)
{
	int i = 0;

	if (!nbr)
		return (1);
	else
	{
		if(nbr < 0)
			nbr = -nbr;
		while (nbr > 0)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
}

int ft_length_X(unsigned int nbr)
{
	int i = 0;

	if (!nbr)
		return (1);
	else
	{
		if(nbr < 0)
			nbr = -nbr;
		while (nbr > 0)
		{
			nbr /= 16;
			i++;
		}
		return (i);
	}
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
