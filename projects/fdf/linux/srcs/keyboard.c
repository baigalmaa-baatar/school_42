/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:09:43 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:35:54 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook_rot(int keycode, t_image *data)
{
if (keycode == 65429) {
		// X-axis rotation
		data->camera->thetaX += 0.05;
	}
	if (keycode == 65434) {
		// X-axis rotation
		data->camera->thetaX -= 0.05;
	}
		if (keycode == 65430) {
		// Y-axis rotation
		data->camera->thetaY += 0.05;
	}
	if (keycode == 65432) {
		// Y-axis rotation
		data->camera->thetaY -= 0.05;
	}
		if (keycode == 65436) {
		// Z-axis rotation
		data->camera->thetaZ += 0.05;
	}
	if (keycode == 65435) {
		// Z-axis rotation
		data->camera->thetaZ -= 0.05;
	}
	return (0);
}

int	key_hook(int keycode, t_image *data)
{
if (keycode == 65307) {
		// CLOSE WINDOW
		mlx_destroy_window(data->mlx, data->window);
	}
	if (keycode == 65362) {
		// UP
		data->camera->move_y -= 10;
	}
	if (keycode == 65364) {
		// DOWN
		data->camera->move_y += 10;
	}
	if (keycode == 65361) {
		// LEFT
		data->camera->move_x -= 10;
	}
	if (keycode == 65363) {
		// RIGHT
		data->camera->move_x += 10;
	}
	if (keycode == 65365) {
		// deeper
		data->camera->depth += 0.1;
	}
	if (keycode == 65366) {
		// lighter
		data->camera->depth -= 0.1;
	}
	if (keycode == 65451) {
		// ZOOM IN
		data->camera->zoom += 0.5;
	}
	if (keycode == 65453) {
		// ZOOM OUT
		data->camera->zoom -= 0.5;
	}
	if (keycode == 65429 || keycode == 65434
		|| keycode == 65430 || keycode == 65432
		|| keycode == 65436 || keycode == 65435)
		key_hook_rot(keycode, data);
	return (0);
}
