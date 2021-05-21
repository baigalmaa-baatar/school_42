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

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122 || c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int main()
{
	printf("This should be 1 \nMy  function : %d\nStd function : %d\n", ft_isalnum(66), isalnum(66));
	printf("This should be 0 \nMy  function : %d\nStd function : %d\n", ft_isalnum(11), isalnum(11));
	return (0);
}