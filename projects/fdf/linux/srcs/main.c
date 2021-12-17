/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:12:20 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:37:34 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render_next_frame(t_image *data)
{
	t_data		img;

	img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	calc_points_x(data, img);
	calc_points_y(data, img);
	mlx_put_image_to_window(data->mlx, data->window, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_image		input;

	if (argc == 2)
	{
		get_map(argv[1], &input);
		input.mlx = mlx_init();
		input.camera = angle_init();
		input.window = mlx_new_window(input.mlx, W_WIDTH, W_HEIGHT, "FDF");
		mlx_loop_hook(input.mlx, render_next_frame, &input);
		mlx_key_hook(input.window, key_hook, &input);
		mlx_mouse_hook(input.window, mouse_hook, &input);
		mlx_loop(input.mlx);
	}
	return (0);
}
