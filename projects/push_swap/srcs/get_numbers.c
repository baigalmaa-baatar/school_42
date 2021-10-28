/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:55:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:45:56 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*ft_malloc_free(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

int	chars_to_int(char **result, long long *nbrs, int start_pos)
{
	int	i;
	int	j;

	i = start_pos;
	j = 0;
	while (result[i] != 0)
	{
		if (!ft_atoi(result[i], &nbrs[j]))
			return (0);
		i++;
		j++;
	}
	return (j);
}

int	if_nbr_duplicate(long long *nbrs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbrs[i] == nbrs[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_numbers(int argc, char **argv, long long *nbrs)
{
	char	**result;
	int		size;

	if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		size = chars_to_int(result, nbrs, 0);
		if (!size)
			return (0);
		ft_malloc_free(result, size);
	}
	else if (argc > 2)
	{
		size = chars_to_int(argv, nbrs, 1);
		if (!size)
			return (0);
	}
	else
		return (0);
	if (!if_nbr_duplicate(nbrs, size))
	{
		return (0);
	}
	return (size);
}
