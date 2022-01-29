/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:51:37 by mkhabou           #+#    #+#             */
/*   Updated: 2021/11/05 11:51:41 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_join(char **tab1, char **tab2)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_tab_len(tab1) + ft_tab_len(tab2) + 1));
	if (tab1)
	{
		while (tab1[i])
		{
			tab[i] = ft_strdup(tab1[i]);
			i++;
		}
	}
	if (tab2)
	{
		while (tab2[j])
		{
			tab[i++] = ft_strdup(tab2[j]);
			j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
