/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:24 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:43:26 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_char_in(char ch, char *delimiters)
{
	while (*delimiters)
	{
		if (ch == *delimiters)
			return (true);
		delimiters++;
	}
	return (false);
}

char	check_open(char open, char c)
{
	if (open == 0)
		open = c;
	else if (open == c)
		open = 0;
	return (open);
}

int	locate_chars(char *s, char *delimiters)
{
	int		i;
	char	open;

	i = 0;
	open = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			open = check_open(open, s[i]);
		else if (open == 0 && is_char_in(s[i], delimiters))
			return (i);
		i++;
	}
	return (-1);
}

int	locate_char(char *s, char delimiter)
{
	char	delimiters[2];

	delimiters[0] = delimiter;
	delimiters[1] = 0;
	return (locate_chars(s, delimiters));
}
