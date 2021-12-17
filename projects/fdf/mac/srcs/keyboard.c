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
	if (keycode == 12)
		data->camera->thetaX += 0.05;
	if (keycode == 13)
		data->camera->thetaX -= 0.05;
	if (keycode == 0)
		data->camera->thetaY += 0.05;
	if (keycode == 1)
		data->camera->thetaY -= 0.05;
	if (keycode == 6)
		data->camera->thetaZ += 0.05;
	if (keycode == 7)
		data->camera->thetaZ -= 0.05;
	return (0);
}

int	key_hook(int keycode, t_image *data)
{
	if (keycode == 65307)
		mlx_destroy_window(data->mlx, data->window);
	if (keycode == 126)
		data->camera->move_y -= 10;
	if (keycode == 125)
		data->camera->move_y += 10;
	if (keycode == 123)
		data->camera->move_x -= 10;
	if (keycode == 124)
		data->camera->move_x += 10;
	if (keycode == 18)
		data->camera->depth += 0.1;
	if (keycode == 19)
		data->camera->depth -= 0.1;
	if (keycode == 12 || keycode == 13
		|| keycode == 0 || keycode == 1
		|| keycode == 6 || keycode == 7)
		key_hook_rot(keycode, data);
	return (0);
}
