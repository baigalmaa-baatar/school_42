/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baigalmaa <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:31:37 by baigalmaa         #+#    #+#             */
/*   Updated: 2021/03/22 20:34:06 by baigalmaa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

int main()
{
	printf("This should be 1 \nMy  function : %d\nStd function : %d\n", ft_isascii(66), isascii(66));
	printf("This should be 0 \nMy  function : %d\nStd function : %d\n", ft_isascii(-1), isascii(-1));
	return (0);
}