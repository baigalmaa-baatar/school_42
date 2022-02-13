/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_double_unquote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:40:43 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:40:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*scan_single_quoted(char *s, int *i)
{
	int		j;
	char	*result;

	result = new_string(ft_strlen(s));
	(*i)++;
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '\'')
		{
			(*i)++;
			return (result);
		}
		result[j++] = s[(*i)++];
	}
	free(result);
	return (NULL);
}

char	*scan_double_quoted(char *s, int *i)
{
	int		j;
	char	*result;

	result = new_string(ft_strlen(s));
	(*i)++;
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '"')
		{
			(*i)++;
			return (result);
		}
		result[j++] = s[(*i)++];
	}
	free (result);
	return (NULL);
}

char	*scan_unquoted(char *s, int *i)
{
	int		j;
	char	*result;

	result = new_string(ft_strlen(s));
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '\'' || s[*i] == '"')
			return (result);
		result[j++] = s[(*i)++];
	}
	return (result);
}
