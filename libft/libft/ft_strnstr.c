/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baigalmaa <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:31:37 by baigalmaa         #+#    #+#             */
/*   Updated: 2021/03/18 13:31:52 by baigalmaa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t len_haystack;
	size_t len_needle;
	char *result;
	
	result = (char *)haystack;
	if (needle[0] == '\0')
		return (result);
	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	if (haystack[0] == '\0' || len_haystack < len_needle)
		return (0);
	i = 0;
	while(len > 0 )
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return(&result[i - j]);
		i++;
		len--;
	}
	return (0);
}