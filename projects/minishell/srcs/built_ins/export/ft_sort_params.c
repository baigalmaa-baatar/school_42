/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:15:03 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 15:40:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_params(char **tab, int size)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], tab[min_index]) <= 0)
			{
				min_index = j;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[min_index]);
		i++;
	}
}
