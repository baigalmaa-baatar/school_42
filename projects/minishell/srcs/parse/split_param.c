/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:25:38 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/31 01:25:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**split_tab(char **tab, int nb)
{
	int	i;
	int	k;
	char **result;

	i = 0;
	result = (char **)malloc((nb + 1) * sizeof(char *));
	while(i < nb)
	{
		result[i] = resolve_env(tab[i]);
		k = 0;
		while (result[i][k])
		{
			if (result[i][k] == 1)
				result[i][k] = '$';
			k++;
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	trim_right(char *s)
{
	int len;

	len = ft_strlen(s);
	while (len > 0 && s[len - 1] == ' ')
	{
		s[len - 1] = 0;
		len--;
	}
}

char	**split_param(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	char	**result;

	tab = alloc_t();
	i = 0;
	j = 0;
	k = 0;
	i = is_space(s, i);
	trim_right(s);
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
				if (s[i] != '$')
					tab[j][k++] = s[i];
				else
					tab[j][k++] = 1;
				i++;
				// if (s[i] != '\'' && !s[i])
				// 	return (1); //add later
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
	result = split_tab(tab, j + 1);
	free_t(tab);
	return (result);
}
