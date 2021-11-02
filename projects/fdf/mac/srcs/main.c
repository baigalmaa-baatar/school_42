#include <mlx.h>
#include "fdf.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void plot_line_low(int x0, int y0, int x1, int y1, t_data img)
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
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
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

void plot_line_high(int x0, int y0, int x1, int y1, t_data img)
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
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
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
void	plot_line(int x0, int y0, int x1, int y1, t_data img)
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

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "FDF");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	plot_line(100, 100, 200, 200, img);
	plot_line(100, 200, 300, 300, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}