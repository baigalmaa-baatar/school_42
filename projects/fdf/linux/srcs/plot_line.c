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
	t_coord	curr;

	yi = 1;
	if (b.y < a.y)
		yi = -1;
	d = (2 * abs(b.y - a.y)) - b.x + a.x;
	curr.y = a.y;
	curr.x = a.x;
	while (curr.x < b.x)
	{
		if (0 <= curr.x && curr.x < W_WIDTH && 0 <= curr.y && curr.y < W_HEIGHT)
		{
			// printf("a point : %d\n", a.x);
			// printf("b point: %d\n", b.x);
			// printf("current : %d\n", x);
			my_mlx_pixel_put(img, curr.x, curr.y, get_color_comb(a, b, curr));
			// printf("color : %d\n", get_color_comb(a, b, x, y));
			// printf("a color : %d\n", a.x);
			// printf("b color : %d\n", b.x);
			// printf("b color : %d\n", x);
		}
		if (d > 0)
		{
			curr.y = curr.y + yi;
			d = d + (2 * (abs(b.y - a.y) - b.x + a.x));
		}
		else
			d = d + 2 * abs(b.y - a.y);
		curr.x++;
	}
}

void	plot_line_high(t_coord a, t_coord b, t_data *img)
{
	int	xi;
	int	d;
	t_coord	curr;

	xi = 1;
	if (b.x < a.x)
		xi = -1;
	d = (2 * abs(b.x - a.x)) - b.y + a.y;
	curr.y = a.y;
	curr.x = a.x;
	curr.color = a.color;
	while (curr.y < b.y)
	{
		if (0 <= curr.x && curr.x < W_WIDTH && 0 <= curr.y && curr.y < W_HEIGHT)
			my_mlx_pixel_put(img, curr.x, curr.y, get_color_comb(a, b, curr));
		if (d > 0)
		{
			curr.x = curr.x + xi;
			d = d + (2 * (abs(b.x - a.x) - b.y + a.y));
		}
		else
			d = d + 2 * abs(b.x - a.x);
		curr.y++;
	}
}

void	plot_line(t_coord a, t_coord b, t_data *img)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			plot_line_low(b, a, img);
			// printf("color : %x\n", a.color);
		}
		else
		{
			plot_line_low(a, b, img);
			// printf("color : %x\n", a.color);
		}
	}
	else
	{
		if (a.y > b.y)
		{
			plot_line_high(b, a, img);
			// printf("color : %x\n", a.color);
		}
		else
		{
			// printf("color b.y ni b.x s ih : %x\n", a.color);
			plot_line_high(a, b, img);
		}
	}
}
