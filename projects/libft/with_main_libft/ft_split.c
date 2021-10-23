/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:20:09 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/23 19:03:58 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_words(char *s, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int	ft_len_word(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_malloc_free(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		nb_ofwords;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nb_ofwords = ft_cnt_words((char *)s, c);
	tab = (char **)malloc((nb_ofwords + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (nb_ofwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_len_word((char *)s, c));
		if (!tab[i])
			return (ft_malloc_free(tab, i));
		s = s + ft_len_word((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int main(void)
{
	char *s = "I am Suzy, yes";
	char **result = ft_split(s, 'y');
	int i = 0;
	while (i < 3)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return(0);
}

