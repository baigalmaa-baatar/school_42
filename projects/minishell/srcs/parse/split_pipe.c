/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:31:41 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/30 23:31:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**split_pipe(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = alloc_t();
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '|')
		{
			j++;
			i++;
			k = 0;
		}
		if (s[i] == '\'')
		{
			tab[j][k++] = s[i++];
			while (s[i] != '\'')
				tab[j][k++] = s[i++];
			tab[j][k] = s[i];
		}
		else if (s[i] == '"')
		{
			tab[j][k++] = s[i++];
			while (s[i] != '"')
				tab[j][k++] = s[i++];
			tab[j][k] = s[i];
		}
		else
			tab[j][k++] = s[i];
		i++;
	}
	tab[j + 1] = 0;
	return (tab);
}
