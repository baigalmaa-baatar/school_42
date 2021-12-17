/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:21:44 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:32:51 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line_low(t_coord a, t_coord b, t_data *img)
{
	int	yi;
	int	d;
	int	x;
	int	y;

	yi = 1;
	if (b.y < a.y)
		yi = -1;
	d = (2 * abs(b.y - a.y)) - b.x + a.x;
	y = a.y;
	x = a.x;
	while (x < b.x)
	{
		if (0 <= x && x < W_WIDTH && 0 <= y && y < W_HEIGHT)
			my_mlx_pixel_put(img, x, y, get_color());
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (abs(b.y - a.y) - b.x + a.x));
		}
		else
			d = d + 2 * abs(b.y - a.y);
		x++;
	}
}

void	plot_line_high(t_coord a, t_coord b, t_data *img)
{
	int	xi;
	int	d;
	int	x;
	int	y;

	xi = 1;
	if (b.x < a.x)
		xi = -1;
	d = (2 * abs(b.x - a.x)) - b.y + a.y;
	y = a.y;
	x = a.x;
	while (y < b.y)
	{
		if (0 <= x && x < W_WIDTH && 0 <= y && y < W_HEIGHT)
			my_mlx_pixel_put(img, x, y, 0x00f4c0ff);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (abs(b.x - a.x) - b.y + a.y));
		}
		else
			d = d + 2 * abs(b.x - a.x);
		y++;
	}
}

void	plot_line(t_coord a, t_coord b, t_data *img, int percentage)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			a.color = get_color(data->min, data->max, percentage);
			plot_line_low(b, a, img);
		}
		else
			plot_line_low(a, b, img);
	}
	else
	{
		if (a.y > b.y)
			plot_line_high(b, a, img);
		else
			plot_line_high(a, b, img);
	}
}
