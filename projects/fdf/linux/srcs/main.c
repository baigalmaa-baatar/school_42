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

void	xaxis_rot(int *y, int *z, double theta)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(theta) + prev_z * sin(theta);
	*z = prev_z * cos(theta) - prev_y * sin(theta);
}

void	yaxis_rot(int *x, int *z, double theta)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(theta) + prev_z * sin(theta);
	*z = prev_z * cos(theta) - prev_x * sin(theta);
}

void	zaxis_rot(int *x, int *y, double theta)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
}

t_camera	*angle_init(void)
{
	t_camera	*camera;
	
	camera = (t_camera *) malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	camera->thetaX = 0;
	camera->thetaY = 0;
	camera->thetaZ = 0;
	camera->depth = 1;
	camera->zoom = 30;
	camera->move_x = 0;
	camera->move_y = 0;
	return (camera);
}

t_coord transform_iso(t_coord coord) 
{
	t_coord result;

	result.x = (coord.x - coord.z) / sqrt(2);
	result.y = (coord.x + 2 * coord.y + coord.z) / sqrt(6);
	return (result);
}

t_coord transform(t_camera camera, t_coord coord) 
{
	t_coord result;
	
	coord.z *= (camera.zoom * camera.depth)/2;
	coord.x *= camera.zoom;
	coord.y *= camera.zoom;
	coord.x += 256;
	coord.y += 144;
	coord.x += camera.move_x;
	coord.y += camera.move_y;
	xaxis_rot(&coord.y, &coord.z, camera.thetaX);
	yaxis_rot(&coord.x, &coord.z, camera.thetaY);
	zaxis_rot(&coord.x, &coord.y, camera.thetaZ);
	
	result = transform_iso(coord);
	return (result);
}

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
void	plot_line(t_coord coord0, t_coord coord1, t_data *img)
{
	int x0 = coord0.x;
	int y0 = coord0.y;
	int x1 = coord1.x;
	int y1 = coord1.y;

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

int	render_next_frame(t_image *data)
{
	t_data		img;
	t_coord		a;
	t_coord		b;
	int x, y;

	img.img = mlx_new_image(data->mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width - 1)
		{
			a.x = x;
			a.y = y;
			a.z = data->points[y][x];
			b.x = x + 1;
			b.y = y;
			b.z = data->points[y][x + 1];
			a = transform(*data->camera, a);
			b = transform(*data->camera, b);
			if (0 <= a.x && a.x < 1280 && 0 <= a.y && a.y < 720) {
				if (0 <= b.x && b.x < 1280 && 0 <= b.y && b.y < 720)
				{
					plot_line(a, b, &img);
				}
			}
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
			a.x = x;
			a.y = y;
			a.z = data->points[y][x];
			b.x = x;
			b.y = y + 1;
			b.z = data->points[y + 1][x];
			a = transform(*data->camera, a);
			b = transform(*data->camera, b);
			if (0 <= a.x && a.x < 1280 && 0 <= a.y && a.y < 720) {
				if (0 <= b.x && b.x < 1280 && 0 <= b.y && b.y < 720)
				{
					plot_line(a, b, &img);
				}
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);

	return 1;
}

int	key_hook(int keycode, t_image *data)
{
	if (keycode == 65307) {
		// CLOSE WINDOW
		mlx_destroy_window(data->mlx, data->window);
	}
	if (keycode == 126) {
		// UP
		data->camera->move_y -= 10;
	}
	if (keycode == 125) {
		// DOWN
		data->camera->move_y += 10;
	}
	if (keycode == 123) {
		// LEFT
		data->camera->move_x -= 10;
	}
	if (keycode == 124) {
		// RIGHT
		data->camera->move_x += 10;
	}
	if (keycode == 18) {
		// deeper
		data->camera->depth += 0.1;
	}
	if (keycode == 19) {
		// lighter
		data->camera->depth -= 0.1;
	}
	if (keycode == 24) {
		// ZOOM IN
		data->camera->zoom += 0.5;
	}
	if (keycode == 27) {
		// ZOOM OUT
		data->camera->zoom -= 0.5;
	}
	if (keycode == 12) {
		// X-axis rotation
		data->camera->thetaX += 0.05;
	}
	if (keycode == 13) {
		// X-axis rotation
		data->camera->thetaX -= 0.05;
	}
		if (keycode == 0) {
		// Y-axis rotation
		data->camera->thetaY += 0.05;
	}
	if (keycode == 1) {
		// Y-axis rotation
		data->camera->thetaY -= 0.05;
	}
		if (keycode == 6) {
		// Z-axis rotation
		data->camera->thetaZ += 0.05;
	}
	if (keycode == 7) {
		// Z-axis rotation
		data->camera->thetaZ -= 0.05;
	}
	return 1;
}

int	mouse_hook(int button, int x, int y, t_image *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		// ZOOM IN
		data->camera->zoom += 0.5;
	}
	if (button == 5)
	{
		// ZOOM OUT
		data->camera->zoom -= 0.5;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd;
	int			width = 0;
	int 		height = 0;
	t_image		input;

	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		width = get_numbers(line, input.points[height]);
		height++;
		free(line);
	}
	input.mlx = mlx_init();
	input.camera = angle_init();
	input.window = mlx_new_window(input.mlx, 1280, 720, "FDF");
	input.height = height;
	input.width = width;
	mlx_loop_hook(input.mlx, render_next_frame, &input);
	mlx_key_hook(input.window, key_hook, &input);
	mlx_mouse_hook(input.window, mouse_hook, &input);
	mlx_loop(input.mlx);
	return (0);
}
