#include <mlx.h>
#include <math.h>
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

double cameraX = -10;
double cameraY = 0;
double cameraZ = -100;
double thetaX = 2.0944;
double thetaY = 2.0944;
double thetaZ = 2.0944;
double epsilonX = 1200;
double epsilonY = 800;
double epsilonZ = 400;

void translate(double aX, double aY, double aZ, double *bX, double *bY) {
    double x = aX - cameraX;
    double y = aY - cameraY;
    double z = aZ - cameraZ;
    double cX = cos(thetaX);
    double cY = cos(thetaY);
    double cZ = cos(thetaZ);
    double sX = sin(thetaX);
    double sY = sin(thetaY);
    double sZ = sin(thetaZ);
    double dX = cY * (sZ * y + cZ * x) - sY * z;
    double dY = sX * (cY * z + sY * (sZ * y + cZ * x)) + cX * (cZ * y - sZ * x);
    double dZ = cX * (cY * z + sY * (sZ * y + cZ * x)) - sX * (cZ * y - sZ * x);
    
    *bX = epsilonZ / dZ * dX + epsilonX;
    *bY = epsilonZ / dZ * dY + epsilonY;
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd;
	int			i;
	int			j;
	int			row = 0;
	int 		col = 0;
	long long	nbrs[1000][1000];
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	col = 0;
	while (get_next_line(fd, &line) == 1)
	{
		// printf("%s\n", line);
		row = get_numbers(line, nbrs[col]);
		col++;
		free(line);
	}
	printf("row is : %d\n", row);
	printf("col is : %d\n", col);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "FDF");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x0 = 0;
	y0 = 0;
	x1 = 20;
	y1 = 20;
	//row = x1 * row;
	//col = y1 * col;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col - 1)
		{	
			double x1, y1, x2, y2;
			translate(j, i, nbrs[j][i], &x1, &y1);
			translate(j + 1, i, nbrs[j + 1][i], &x2, &y2);
			printf("%0.3lf %0.3lf -> %0.3lf %0.3lf\n", x1, y1, x2, y2);
			if (0 <= x1 && x1 < 600 && 0 <= y1 && y1 < 600) {
				if (0 <= x2 && x2 < 600 && 0 <= y2 && y2 < 600) {
					plot_line(x1, y1, x2, y2, img);
				}
			}
			j++;
		}
		i++;
	}

	j = 0;
	while (j < col)
	{
		i = 0;
		while (i < row - 1)
		{	
			double x1, y1, x2, y2;
			translate(j, i, nbrs[j][i], &x1, &y1);
			translate(j, i + 1, nbrs[j][i + 1], &x2, &y2);
			printf("%0.3lf %0.3lf -> %0.3lf %0.3lf\n", x1, y1, x2, y2);
			if (0 <= x1 && x1 < 600 && 0 <= y1 && y1 < 600) {
				if (0 <= x2 && x2 < 600 && 0 <= y2 && y2 < 600) {
					plot_line(x1, y1, x2, y2, img);
				}
			}
			i++;
		}
		j++;
	}
	// while (x0 < row)
	// {
	// 	y0 = 0;
	// 	y1 = 20;
	// 	while (y0 < col)
	// 	{
	// 		plot_line(x0, y0, x1, y0, img);
	// 		plot_line(x0, y0, x0, y1, img);
	// 		plot_line(x0, y1, x1, y1, img);
	// 		plot_line(x1, y0, x1, y1, img);
	// 		y0 += 20;
	// 		y1 += 20;
	// 	}
	// 	x0 += 20;
	// 	x1 += 20;
	// }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}