/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:02:56 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/12 22:03:17 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*t;

	t = (char *)b;
	i = 0;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
