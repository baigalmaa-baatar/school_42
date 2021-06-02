/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:36:14 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 11:51:54 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	total_size;
	unsigned int	i;

	total_size = count * size;
	ptr = malloc (total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (total_size)
	{
		ptr[i] = 0;
		i++;
		total_size--;
	}
	return ((void *)ptr);
}
