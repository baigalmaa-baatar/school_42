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

double cameraX = 38;
double cameraY = 22;
double cameraZ = 40;
double zFactor = 1;
double xyFactor = 10;

// https://en.wikipedia.org/wiki/Euler_angles#Tait%E2%80%93Bryan_angles
double thetaX = 0.785398; // 45 degree
double thetaY = 0.785398; // 45 degree
double thetaZ = -0.785398; // -45 degree

double epsilonX = 200;
double epsilonY = -20;
double epsilonZ = 50;

void transform(double aX, double aY, double aZ, double *bX, double *bY) {
	// https://en.wikipedia.org/wiki/3D_projection#Mathematical_formula
    // double x = aX - cameraX;
    // double y = aY - cameraY;
    // double z = aZ - cameraZ;
    // double cX = cos(thetaX);
    // double cY = cos(thetaY);
    // double cZ = cos(thetaZ);
    // double sX = sin(thetaX);
    // double sY = sin(thetaY);
    // double sZ = sin(thetaZ);
    // double dX = cY * (sZ * y + cZ * x) - sY * z;
    // double dY = sX * (cY * z + sY * (sZ * y + cZ * x)) + cX * (cZ * y - sZ * x);
    // double dZ = cX * (cY * z + sY * (sZ * y + cZ * x)) - sX * (cZ * y - sZ * x);

    // *bX = epsilonZ / dZ * dX + epsilonX;
    // *bY = epsilonZ / dZ * dY + epsilonY;

	// https://en.wikipedia.org/wiki/Isometric_projection#Mathematics
	aZ *= zFactor;
	*bX = (aX - aZ) / sqrt(2);
	*bY = (aX + 2 * aY + aZ) / sqrt(6);
	*bX *= xyFactor;
	*bY *= xyFactor;
	*bX += 200;
	*bY += 200;

	// printf("%0.3lf %0.3lf\n", *bX, *bY);
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

int	render_next_frame(t_image *data) {
	int x, y;
	double x1, y1, x2, y2;
	t_data		img;

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
			if (0 <= x1 && x1 < 1280 && 0 <= y1 && y1 < 720) {
				if (0 <= x2 && x2 < 1280 && 0 <= y2 && y2 < 720) {
					plot_line(x1, y1, x2, y2, &img);
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
			transform(x, y, data->points[y][x], &x1, &y1);
			transform(x, y + 1, data->points[y + 1][x], &x2, &y2);
			if (0 <= x1 && x1 < 1280 && 0 <= y1 && y1 < 720) {
				if (0 <= x2 && x2 < 1280 && 0 <= y2 && y2 < 720) {
					plot_line(x1, y1, x2, y2, &img);
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
	if (keycode == 65362) {
		// UP
		cameraX += 1;
		zFactor += 0.1;
	}
	if (keycode == 65364) {
		// DOWN
		cameraX -= 1;
		zFactor -= 0.1;
	}
	if (keycode == 65361) {
		// LEFT
		cameraY -= 1;
	}
	if (keycode == 65363) {
		// RIGHT
		cameraY += 1;
	}
	if (keycode == 65365) {
		// PAGE UP
		cameraZ += 1;
	}
	if (keycode == 65366) {
		// PAGE DOWN
		cameraZ -= 1;
	}
	if (keycode == 65451) {
		// ZOOM IN
		xyFactor += 0.5;
	}
	if (keycode == 65453) {
		// ZOOM OUT
		xyFactor -= 0.5;
	}

	double centerX = data->width / 2;
	double centerY = data->height / 2;
	double centerZ = 5;
	double distance = sqrt(pow(cameraX - centerX, 2) + pow(cameraY - centerY, 2) + pow(cameraZ, 2));

	// https://www.quora.com/How-do-I-find-the-angle-of-a-3D-vector-i-e-A-2i-3j-5k
	thetaX = asin((cameraX - centerX) / distance);
	thetaY = asin((cameraY - centerY) / distance);
	thetaZ = asin((cameraZ - centerZ) / distance);

	if (keycode == 13) {
		// W
		epsilonX += 1;
	}
	if (keycode == 1) {
		// S
		epsilonX -= 1;
	}
	if (keycode == 0) {
		// A
		epsilonY -= 1;
	}
	if (keycode == 2) {
		// D
		epsilonY += 1;
	}
	if (keycode == 17) {
		// T
		epsilonZ += 1;
	}
	if (keycode == 5) {
		// G
		epsilonZ -= 1;
	}

	// printf("%d\n", keycode);

	return 1;
}

int	mouse_hook(int button, int x, int y, t_image *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (button == 4)
	{
		// ZOOM IN
		xyFactor += 0.5;
	}
	if (button == 5)
	{
		// ZOOM OUT
		xyFactor -= 0.5;
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
		// printf("%s\n", line);
		width = get_numbers(line, input.points[height]);
		height++;
		free(line);
	}
	// printf("width is : %d\n", width);
	// printf("heigth is : %d\n", height);
	input.mlx = mlx_init();
	input.window = mlx_new_window(input.mlx, 1280, 720, "FDF");
	input.height = height;
	input.width = width;
	mlx_loop_hook(input.mlx, render_next_frame, &input);
	mlx_key_hook(input.window, key_hook, &input);
	mlx_mouse_hook(input.window, mouse_hook, &input);
	mlx_loop(input.mlx);
	return (0);
}
