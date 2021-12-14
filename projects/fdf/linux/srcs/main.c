/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:12:20 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/10 19:12:21 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/fdf.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_image {
	long long points[1000][1000];
	int width;
	int height;
	void *mlx;
	void *window;
} t_image;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void plot_line_low(int x0, int y0, int x1, int y1, t_data *img)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	int d;
	int x;
	int y;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	y = y0;
	x = x0;
	while (x < x1)
	{
		my_mlx_pixel_put(img, x, y, 0x00f4c0ff);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		x++;
	}
}

void plot_line_high(int x0, int y0, int x1, int y1, t_data *img)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	int d;
	int x;
	int y;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	y = y0;
	x = x0;
	while (y < y1)
	{
		my_mlx_pixel_put(img, x, y, 0x00f4c0ff);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		y++;
	}
}
void	plot_line(int x0, int y0, int x1, int y1, t_data *img)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(x1, y1, x0, y0, img);
		else
			plot_line_low(x0, y0, x1, y1, img);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(x1, y1, x0, y0, img);
		else
			plot_line_high(x0, y0, x1, y1, img);
	}
}

double xyFactor = 20;
double zFactor = 1;

void	transform(double aX, double aY, double aZ, double *bX, double *bY)
{
	aZ *= zFactor;
	*bX = (aX - aZ)/sqrt(2);
	*bY = (aX + 2 * aY + aZ)/sqrt(6);
	*bX *= xyFactor;
	*bY *= xyFactor;
	*bX += 256;
	*bY += 144;
}

int	render_next_frame(t_image *data)
{
	int	x;
	int	y;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	t_data	img;

	img.img = mlx_new_image(data->mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width - 1)
		{
			transform(x, y, data->points[y][x], &x1, &y1);
			transform(x + 1, y, data->points[y][x + 1], &x2, &y2);
			plot_line(x1, y1, x2, y2, &img);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height - 1)
		{
			transform(x, y, data->points[y][x], &x1, &y1);
			transform(x, y + 1, data->points[y + 1][x], &x2, &y2);
			plot_line(x1, y1, x2, y2, &img);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (1);
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd;
	int			width;
	int 		height;
	t_image		input;

	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	height = 0;
	width = 0;
	while (get_next_line(fd, &line) == 1)
	{
		width = get_numbers(line, input.points[height]);
		height++;
		free(line);
	}
	input.mlx = mlx_init();
	input.window = mlx_new_window(input.mlx, 1280, 720, "FDF");
	input.height = height;
	input.width = width;
	mlx_loop_hook(input.mlx, render_next_frame, &input);
	mlx_loop(input.mlx);

	return (0);
}
