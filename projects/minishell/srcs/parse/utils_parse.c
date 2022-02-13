/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:18:00 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:05:57 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	str_err(char *err, int i)
{
	write(1, err, ft_strlen(err));
	return (i);
}

int	trim(char *s)
{
	int	result;

	result = skip_spaces(s, 0);
	trim_right(s);
	return (result);
}

int	skip_spaces(char	*str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

static int	ft_find(char *haystack, char *needle, int l, int len_i)
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

int	find_pos(const char *haystack, const char *needle, int len)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		if (haystack[i] != needle[0])
			i++;
		else if (haystack[i] == needle[0])
		{
			if (ft_find((char *)&haystack[i], (char *)needle, l, len - i) == 1)
				return (i);
			else
				i++;
		}
	}
	return (-1);
}
