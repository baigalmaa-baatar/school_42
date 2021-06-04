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

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

int main()
{
	printf("This should be 1 \nMy  function : %d\nStd function : %d\n", ft_isprint(66), isprint(66));
	printf("This should be 0 \nMy  function : %d\nStd function : %d\n", ft_isprint(0), isprint(0));
	return (0);
}