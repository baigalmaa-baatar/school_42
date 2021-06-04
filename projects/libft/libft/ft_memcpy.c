/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:06:17 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 13:49:53 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!n || ptr_dst == ptr_src)
		return ((void *)dst);
	while (n)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return ((void *)dst);
}
