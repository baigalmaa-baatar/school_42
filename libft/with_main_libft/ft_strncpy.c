/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:51:11 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/03 11:51:13 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	if (!n)
		return(0);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

// int main()
// {
// 	// char chararray1[6];
// 	// char chararray2[6];

// 	// char b1[0xF0] = {0};
// 	char b2[0xF0] = {0};

// 	// strncpy(b1, ((void *)0), 2);
// 	// ft_strncpy(b2, ((void *)0), 2);
	
// 	// printf("Std function  : %s\n", strncpy(b1, ((void *)0), 2));
// 	printf(" My function  : %s\n", ft_strncpy(b2, ((void *)0), 2));

// 	return (0);
// }
