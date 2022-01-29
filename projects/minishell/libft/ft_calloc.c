/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:36:21 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/15 15:15:44 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;
	size_t	i;

	i = 0;
	t = malloc(count * size);
	if (t == NULL)
		return (NULL);
	t = ft_memset(t, 0, count * size);
	return (t);
}
