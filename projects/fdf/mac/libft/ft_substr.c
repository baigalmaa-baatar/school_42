/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:53:52 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/02 10:59:24 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
