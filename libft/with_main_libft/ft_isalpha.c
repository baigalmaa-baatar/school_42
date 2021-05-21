/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baigalmaa <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:31:37 by baigalmaa         #+#    #+#             */
/*   Updated: 2021/03/18 13:31:52 by baigalmaa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}

#include <stdio.h>

int main()
{
	printf("This should be 1 : %d\n", ft_isalpha(66));
	printf("This should be 0 : %d\n", ft_isalpha(10));
	return (0);
}