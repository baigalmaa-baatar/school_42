/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:16:27 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/28 04:16:29 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#define ERR_OPE "Operation error!\n"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_substr(const char *s, unsigned int start_pos, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start_pos)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (start_pos + len > ft_strlen(s))
		len = ft_strlen(s) - start_pos;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (++i - 1 < len)
		*(res + i - 1) = *(s + start_pos + i - 1);
	*(res + i - 1) = '\0';
	return (res);
}

char	*strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			i;
	unsigned int	length;

	if (!s1 || !s2)
		return (0);	
	length = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	i = 0;
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

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

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
