/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:36:14 by bbaatar           #+#    #+#             */
/*   Updated: 2021/04/28 18:36:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;
	unsigned int total_size;
	unsigned int i;

	total_size = count * size;
	if(!(ptr = malloc (total_size)))
		return(NULL);
	i = 0;
	while (total_size)
	{
		ptr[i] = 0;
		i++;
		total_size--;
	}
	return ((void *)ptr);
}

int main()
{
	int count = 4;
	int *d1;

	d1 = ft_calloc(count, sizeof(int));
	// size = ft_calloc(count, sizeof(char));

	// printf("Std function : %p\nMy function  : %p\n", d1, d2);
	printf("Std function : %p\n", d1);

	return (0);
}