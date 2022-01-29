/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:47:32 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/10 12:21:56 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	i = len_d;
	if (dstsize <= len_d)
		return (len_s + dstsize);
	j = 0;
	while (j < (dstsize - len_d - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_s + len_d);
}
