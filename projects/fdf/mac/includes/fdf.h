/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:32 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:42:52 by bbaatar          ###   ########.fr       */
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
// # include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct	s_camera
{
	double	thetaX;
	double	thetaY;
	double	thetaZ;
	double	depth;
	double	zoom;
	double		move_x;
	double		move_y;
}	t_camera;

typedef struct	s_mouse
{
	char	clicked;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_image {
	long long points[1000][1000];
	int width;
	int height;
	void *mlx;
	void *window;
	t_camera	*camera;
}	t_image;

int	main(int argc, char *argv[]);
int	get_numbers(char *line, long long *nbrs);

#endif
