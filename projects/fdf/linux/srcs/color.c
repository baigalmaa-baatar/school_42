/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 02:17:43 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 02:17:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double percent(int min, int max, int current)
{
	double	above; 
	double	under;

	above = current - min;
	under = max - min;
	if (max == min)
		return (1.0);
	return (above/under);
}

int	get_z_color(t_image *data, int z)
{
	double	percentage;

	percentage = percent(data->min, data->max, z);

	if (percentage <= 0.25)
		return (0x152069);
	else if (0.25 < percentage && percentage <= 0.5)
		return (0x244A80);
	else if (0.5 < percentage && percentage <= 0.75)
		return (0x377A98);
	else if (0.75 < percentage)
		return (0x88DE80);
	else return (0x88DE80);
}

int	rgb_comb(int a_point, int b_point, double percentage)
{
	return ((int)((1 - percentage) * a_point + percentage * b_point));
}

int	get_color_comb(t_coord a, t_coord b, t_coord curr)
{
	int	r_col;
	int	g_col;
	int	b_col;
	double percentage;

	if (b.color == curr.color)
		return (curr.color);
	if (abs(a.x - b.x) > abs(b.y - a.y))
		percentage = percent(a.x, b.x, curr.x);
	else
		percentage = percent(a.y, b.y, curr.y);
	r_col = rgb_comb((a.color >> 16) & 0xFF, 
						(b.color >> 16) & 0xFF,
						percentage);
	g_col = rgb_comb((a.color >> 8) & 0xFF,
						(b.color >> 8) & 0xFF,
						percentage);
	b_col = rgb_comb(a.color & 0xFF,
						b.color & 0xFF,
						percentage);
	return ((r_col << 16) | (g_col << 8) | b_col);
}
