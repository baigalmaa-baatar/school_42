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

char	**split_pipe_tab(char **tab, int nb)
{
	int	i;
	char **result;

	i = 0;
	result = (char **)malloc((nb + 1) * sizeof(char *));
	while(i < nb)
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**split_pipe(char *s, int *nb_processes)
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
	// TODO: need to recreate tab with the correct size
	result = split_pipe_tab(tab, j + 1);
	free_t(tab);
	*nb_processes = j + 1;
	return (result);
}