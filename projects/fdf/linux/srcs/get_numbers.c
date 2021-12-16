/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:55:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/30 13:36:06 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void get_min_max(t_image input)
// {
// 	int min;
// 	int max;
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	printf("min is : %d\n", input.min);
// 	min = input.points[x][y];
// 	max = input.points[x][y];
// 	while (x < input.width)
// 	{
// 		y = 0;
// 		while (y < input.height)
// 		{
// 			if (input.points[x][y] < min)
// 				min = input.points[x][y];
// 			if (input.points[x][y] > max)
// 				max = input.points[x][y];
// 			y++;
// 		}
// 		x++;
// 	}
// 	input.min = min;
// 	input.max = max;
// 	printf("min is : %d\n", input.min);
// 	printf("max is : %d\n", input.max);
// }

static void	*ft_malloc_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
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
		if (!ft_atoi_changed(result[i], &nbrs[j]))
			return (0);
		i++;
		j++;
	}
	return (j);
}

int	get_numbers(char *line, long long *nbrs)
{
	char	**result;
	int		size;

	result = ft_split_changed(line, ' ');
	size = chars_to_int(result, nbrs, 0);
	ft_malloc_free(result);
	if (!size)
		return (0);
	return (size);
}
