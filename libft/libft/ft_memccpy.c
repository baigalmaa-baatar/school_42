/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:00:25 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 13:48:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!n || ptr_dst == ptr_src)
		return (0);
	i = 0;
	while (n > i)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
		{
			return ((void *)&ptr_dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
