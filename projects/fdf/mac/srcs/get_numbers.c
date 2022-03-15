/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:55:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/18 16:25:50 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	*ft_malloc_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
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
		{
			printf("here\n");
			return (0);
		}
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
	if (size < 0)
		return (0);
	return (size);
}

void	min_max(t_image *input)
{
	int	x;
	int	y;
	int	min;
	int	max;

	x = 0;
	y = 0;
	min = input->points[x][y];
	max = input->points[x][y];
	y = 0;
	while (y < input->height)
	{
		x = 0;
		while (x < input->width)
		{
			if (input->points[y][x] < min)
				min = input->points[y][x];
			if (input->points[y][x] > max)
				max = input->points[y][x];
			x++;
		}
		y++;
	}
	input->min = min;
	input->max = max;
}

int	get_map(char *argv, t_image *input)
{
	char	*line;
	int		fd;
	int		width;
	int		height;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	width = 0;
	height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		width = get_numbers(line, input->points[height]);
		height++;
		free (line);
	}
	free (line);
	input->height = height;
	input->width = width;
	min_max(input);
	return (0);
}
