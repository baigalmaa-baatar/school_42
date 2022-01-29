/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:40:32 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/24 01:40:34 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

#define ERR_OPE "Operation error!\n"

char	**alloc_t(char **arr)
{
	int i;

	arr = (char **)malloc(100 * sizeof(char *));
	memset (arr, 0, 100 * sizeof(char *));
	i = 0;
	while (i < 100)
	{
		arr[i] = (char *)malloc(100 * sizeof(char));
		memset (arr[i], 0, 100 * sizeof(char));
		i++;
	}
	return (arr);
}

char	**split_tab(char **tab, int nb)
{
	int	i;

	i = 0;
	while(i < nb)
	{
		if(!(tab[i] = ft_strdup(resolve_env(tab[i]))))
			break;
		i++;
	}
	return (tab);
}

char	**split(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**tab = NULL;

	tab = alloc_t(tab);
	i = 0;
	j = 0;
	k = 0;
	i = is_space(s, i);
	while (s[i])
	{
		if (s[i] == ' ')
		{
			j++;
			k = 0;
			i = is_space(s, i);
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
			{
				// if (s[i] != '\'' && !s[i])
				// 	return (1); //add later
				tab[j][k++] = s[i++];
			}
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
			{
				// if (s[i] != '"' && !s[i])
				// 	return (1); //add later
				tab[j][k++] = s[i++];
			}
		}
		else if (s[i] == '\\')
		{
			i++;
			tab[j][k++] = s[i];
		}
		else
			tab[j][k++] = s[i];
		i++;
	}
	return (split_tab(tab, j + 1));
}