// #include <mlx.h>
// #include "../includes/fdf.h"

// typedef struct s_data
// {
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;
// } t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void plot_line_low(int x0, int y0, int x1, int y1, t_data img)
// {
// 	int dx = x1 - x0;
// 	int dy = y1 - y0;
// 	int yi = 1;
// 	int d;
// 	int x;
// 	int y;

// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	d = (2 * dy) - dx;
// 	y = y0;
// 	x = x0;
// 	while (x < x1)
// 	{
// 		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
// 		if (d > 0)
// 		{
// 			y = y + yi;
// 			d = d + (2 * (dy - dx));
// 		}
// 		else
// 			d = d + 2 * dy;
// 		x++;
// 	}
// }

// void plot_line_high(int x0, int y0, int x1, int y1, t_data img)
// {
// 	int dx = x1 - x0;
// 	int dy = y1 - y0;
// 	int xi = 1;
// 	int d;
// 	int x;
// 	int y;

// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dx = -dx;
// 	}
// 	d = (2 * dx) - dy;
// 	y = y0;
// 	x = x0;
// 	while (y < y1)
// 	{
// 		my_mlx_pixel_put(&img, x, y, 0x00f4c0ff);
// 		if (d > 0)
// 		{
// 			x = x + xi;
// 			d = d + (2 * (dx - dy));
// 		}
// 		else
// 			d = d + 2 * dx;
// 		y++;
// 	}
// }
// void	plot_line(int x0, int y0, int x1, int y1, t_data img)
// {
// 	if (abs(y1 - y0) < abs(x1 - x0))
// 	{
// 		if (x0 > x1)
// 			plot_line_low(x1, y1, x0, y0, img);
// 		else
// 			plot_line_low(x0, y0, x1, y1, img);
// 	}
// 	else
// 	{
// 		if (y0 > y1)
// 			plot_line_high(x1, y1, x0, y0, img);
// 		else
// 			plot_line_high(x0, y0, x1, y1, img);
// 	}
// }

// int	main(int argc, char *argv[])
// {
// 	char		*line;
// 	int			fd;
// 	// int			i;
// 	int			row = 0;
// 	int 		col = 0;
// 	long long	nbrs[10000];
// 	int			x0;
// 	int			x1;
// 	int			y0;
// 	int			y1;
// 	void		*mlx;
// 	void		*mlx_win;
// 	t_data		img;

// 	if (argc <= 1)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		row = get_numbers(line, nbrs);
// 		col++;
// 		free(line);
// 	}
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 600, 600, "FDF");
// 	img.img = mlx_new_image(mlx, 600, 600);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	x0 = 0;
// 	y0 = 0;
// 	x1 = 20;
// 	y1 = 20;
// 	row = x1 * row;
// 	col = y1 * col;
// 	while (x0 < row)
// 	{
// 		y0 = 0;
// 		y1 = 20;
// 		while (y0 < col)
// 		{
// 			plot_line(x0, y0, x1, y0, img);
// 			plot_line(x0, y0, x0, y1, img);
// 			plot_line(x0, y1, x1, y1, img);
// 			plot_line(x1, y0, x1, y1, img);
// 			y0 += 20;
// 			y1 += 20;
// 		}
// 		x0 += 20;
// 		x1 += 20;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
    (void)keycode;
    if (keycode == 65361)
        printf("Hello from key_hook LEFT!\n");
    if (keycode == 65363)
        printf("Hello from key_hook RIGHT!\n");
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
    return (0);
}