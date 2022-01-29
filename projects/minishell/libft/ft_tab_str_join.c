/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_str_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:52:17 by mkhabou           #+#    #+#             */
/*   Updated: 2021/11/05 11:52:20 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_str_join(char **tab, char *str)
{
	int		i;
	char	**final_tab;

	i = 0;
	final_tab = malloc(sizeof(char *) * (ft_tab_len(tab) + 2));
	if (tab)
	{
		while (tab[i])
		{
			final_tab[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	final_tab[i] = ft_strdup(str);
	final_tab[i + 1] = NULL;
	return (final_tab);
}
