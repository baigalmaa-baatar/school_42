/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:30:56 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/22 13:30:52 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(const char *s, char c, int count_tab, char **split)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < count_tab)
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			split[j][k] = s[i];
			i++;
			k++;
		}
		split[j][k] = '\0';
		j++;
		k = 0;
	}
	split[j] = NULL;
}

static int	*ft_splitlen(const char *s, char c, int count_tab)
{
	int	i;
	int	j;
	int	k;
	int	*tab;

	i = 0;
	j = 0;
	k = 0;
	tab = malloc(sizeof(int) * (count_tab + 1));
	if (tab == NULL)
		return (NULL);
	while (i < count_tab)
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		tab[i] = j - k;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static char	**ft_new_tab(char **split, const char *s, int count_tab, char c)
{
	int	i;
	int	x;
	int	*tab;

	x = 0;
	tab = ft_splitlen(s, c, count_tab);
	while (x < count_tab)
	{
		split[x] = malloc(sizeof(char) * (tab[x] + 1));
		if (split[x] == NULL)
		{
			i = 0;
			while (i < x)
			{
				free(split[i]);
				i++;
			}
			free(split);
			return (NULL);
		}
		x++;
	}
	free(tab);
	ft_fill(s, c, count_tab, split);
	return (split);
}

static int	ft_count(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	if (!s || !s[i])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	if (i == (int)ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count_tab;

	count_tab = ft_count(s, c);
	split = malloc(sizeof(*split) * (count_tab + 1));
	if (split == NULL)
		return (NULL);
	if (count_tab == 0)
	{
		split[0] = NULL;
		return (split);
	}
	return (ft_new_tab(split, s, count_tab, c));
}
