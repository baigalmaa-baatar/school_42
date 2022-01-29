/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:25:35 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/13 22:18:16 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	ch;

	ch = c;
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
