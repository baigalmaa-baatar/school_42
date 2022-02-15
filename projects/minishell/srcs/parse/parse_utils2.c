/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:48:02 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 04:29:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	trim_right(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0 && s[len - 1] == ' ')
	{
		s[len - 1] = 0;
		len--;
	}
}

char	*new_string(int capacity)
{
	char	*result;

	capacity += 1;
	result = (char *)my_malloc(capacity * sizeof(char));
	ft_memset(result, 0, capacity * sizeof(char));
	return (result);
}

void	copy_then_free(char *src, int *i, char *dst)
{
	int	j;

	j = 0;
	while (dst[j])
		src[(*i)++] = dst[j++];
	free(dst);
}

bool	env_char(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (true);
	return (false);
}

char	*free_res(char *res)
{
	free(res);
	return (0);
}
