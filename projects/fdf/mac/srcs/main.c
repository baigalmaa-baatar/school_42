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

void draw_square(t_data img, int x_ref, int y_ref)
{
	int x;
	int y;

	x = x_ref;
	y = y_ref;
	while (x < (x_ref + 20) && y < (y_ref + 20))
	{
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
		x++;
		y++;
	}
	x = x_ref;
	y = y_ref;
	while (x < (x_ref + 20))
	{
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
		x++;
	}
	x = x_ref + 20;
	y = y_ref;
	while (x < (x_ref + 40) && y < (y_ref + 40))
	{
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
		x++;
		y++;
	}
	x = x_ref + 20;
	y = y_ref + 20;
	while (x < (x_ref + 40))
	{
		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
		x++;
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "FDF");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	k = 100;
	while (k < 300)
	{
		i = k;
		j = 100;
		while (j < 300)
		{
			draw_square(img, i, j);
			j += 20;
			i += 20;
		}
		k += 20;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}