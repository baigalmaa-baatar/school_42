/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:48:02 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:48:04 by bbaatar          ###   ########.fr       */
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
	result = (char *)malloc(capacity * sizeof(char));
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
