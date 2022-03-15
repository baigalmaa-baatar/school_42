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
	if (keycode == 18)
		data->camera->thetax += 0.05;
	if (keycode == 19)
		data->camera->thetax -= 0.05;
	if (keycode == 20)
		data->camera->thetay += 0.05;
	if (keycode == 21)
		data->camera->thetay -= 0.05;
	if (keycode == 22)
		data->camera->thetaz += 0.05;
	if (keycode == 23)
		data->camera->thetaz -= 0.05;
	return (0);
}

int	key_hook(int keycode, t_image *data)
{
	if (keycode == 53)
		data->finished = 1;
	if (keycode == 126)
		data->camera->move_y -= 10;
	if (keycode == 125)
		data->camera->move_y += 10;
	if (keycode == 123)
		data->camera->move_x -= 10;
	if (keycode == 124)
		data->camera->move_x += 10;
	if (keycode == 34)
		data->camera->depth += 0.1;
	if (keycode == 35)
		data->camera->depth -= 0.1;
	if (keycode == 24)
		data->camera->zoom += 0.5;
	if (keycode == 27)
		data->camera->zoom -= 0.5;
	if (keycode == 18 || keycode == 19
		|| keycode == 20 || keycode == 21
		|| keycode == 22 || keycode == 23)
		key_hook_rot(keycode, data);
	return (0);
}
