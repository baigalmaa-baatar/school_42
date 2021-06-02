/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:01:26 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 12:01:49 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		if (ptr_str[i] == (unsigned char)c)
		{
			return (&ptr_str[i]);
		}
		i++;
	}
	return (NULL);
}
