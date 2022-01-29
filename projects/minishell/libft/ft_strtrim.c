/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:10:15 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/15 20:55:20 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char s, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (s == set[i])
			count++;
		i++;
	}
	return (count);
}

static int	ft_count_len(char const *s1, char const *s2, size_t l)
{
	int	new_len;

	new_len = 0;
	while (s1[new_len] && ft_check(s1[new_len], s2) != 0)
		new_len++;
	if ((int)l == new_len)
		return (0);
	while (ft_check((char)s1[l - 1], s2) != 0)
	{
		l--;
		new_len++;
	}
	return (new_len);
}

static char	*ft_copy(char *copy, char const *s1, char const *s2, size_t l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && ft_check((char)s1[i], s2) != 0)
		i++;
	if (i == (int)l)
	{
		copy[0] = '\0';
		return (copy);
	}
	while (l && s1[i])
	{
		copy[j] = s1[i];
		i++;
		j++;
		l--;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	l;
	char	*copy;

	if (s1 == NULL)
		return (NULL);
	else if (s1 != NULL && s2 == NULL)
	{
		copy = ft_strdup(s1);
		if (copy == NULL)
			return (NULL);
		return (copy);
	}
	else
	{
		l = ft_strlen(s1) - ft_count_len(s1, s2, ft_strlen(s1));
		copy = malloc(sizeof(char) * (l + 1));
		if (copy == NULL)
			return (NULL);
		copy = ft_copy(copy, s1, s2, l);
	}
	return (copy);
}
