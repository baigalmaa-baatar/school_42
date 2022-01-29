/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:18:51 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/12 16:54:40 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len && s[start])
	{
		new[i] = s[start];
		i++;
		j++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
