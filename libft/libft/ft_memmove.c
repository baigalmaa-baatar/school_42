/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:07:25 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 12:12:21 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!ptr_dst && !ptr_src)
		return (NULL);
	if (ptr_dst < ptr_src)
	{
		while (len)
		{
			*ptr_dst++ = *ptr_src++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
	}
	return (dst);
}
