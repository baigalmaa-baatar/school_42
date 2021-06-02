/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:53:52 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/27 11:43:42 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1 + beg);
	if (end)
		while (s1[end + beg - 1] != 0 && ft_strchr(set, s1[end + beg - 1]) != 0)
			end--;
	new = malloc(sizeof(char) * end + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, s1 + beg, end);
	new[end] = '\0';
	return (new);
}
