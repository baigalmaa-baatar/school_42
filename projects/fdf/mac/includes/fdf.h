/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:32 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/18 16:53:30 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"

# define W_HEIGHT			1080
# define W_WIDTH			1920

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_coord;

typedef struct s_camera
{
	double		thetax;
	double		thetay;
	double		thetaz;
	double		depth;
	double		zoom;
	double		move_x;
	double		move_y;
}	t_camera;

typedef struct s_mouse
{
	char		clicked;
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
}	t_mouse;

typedef struct s_image
{
	int			finished;
	int			width;
	int			height;
	int			min;
	int			max;
	void		*mlx;
	void		*window;
	long long	points[1000][1000];
	t_camera	*camera;

}	t_image;

void		calc_points_x(t_image *data, t_data img);
void		calc_points_y(t_image *data, t_data img);
void		plot_line(t_coord a, t_coord b, t_data *img);
void		xaxis_rot(int *y, int *z, double theta);
void		yaxis_rot(int *x, int *z, double theta);
void		zaxis_rot(int *x, int *y, double theta);
void		get_min_max(t_image input);
int			main(int argc, char *argv[]);
int			err_handler(char *str);
int			get_z_color(t_image *data, int z);
int			get_color_comb(t_coord a, t_coord b, t_coord curr);
int			get_map(char *argv, t_image *input);
int			key_hook(int keycode, t_image *data);
int			mouse_hook(int button, int x, int y, t_image *data);
t_camera	*angle_init(void);

#endif
