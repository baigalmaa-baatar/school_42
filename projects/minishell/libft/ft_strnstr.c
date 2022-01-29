/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:44:24 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/15 14:38:47 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *haystack, char *needle, int l, size_t len_i)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	i = 0;
	count = 0;
	while (len_i && haystack[i] && haystack[i] == needle[j])
	{
		i++;
		j++;
		len_i--;
		count++;
	}
	if (count == l)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		l;

	i = 0;
	l = ft_strlen(needle);
	if (l == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] != needle[0])
			i++;
		else if (haystack[i] == needle[0])
		{
			if (ft_find((char *)&haystack[i], (char *)needle, l, len - i) == 1)
				return ((char *)&haystack[i]);
			else
				i++;
		}
	}
	return (0);
}
