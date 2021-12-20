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
	if (keycode == 65429)
		data->camera->thetax += 0.05;
	if (keycode == 65434)
		data->camera->thetax -= 0.05;
	if (keycode == 65430)
		data->camera->thetay += 0.05;
	if (keycode == 65432)
		data->camera->thetay -= 0.05;
	if (keycode == 65436)
		data->camera->thetaz += 0.05;
	if (keycode == 65435)
		data->camera->thetaz -= 0.05;
	return (0);
}

int	key_hook(int keycode, t_image *data)
{
	if (keycode == 65307)
		data->finished = 1;
	if (keycode == 65362)
		data->camera->move_y -= 10;
	if (keycode == 65364)
		data->camera->move_y += 10;
	if (keycode == 65361)
		data->camera->move_x -= 10;
	if (keycode == 65363)
		data->camera->move_x += 10;
	if (keycode == 65365)
		data->camera->depth += 0.1;
	if (keycode == 65366)
		data->camera->depth -= 0.1;
	if (keycode == 65451)
		data->camera->zoom += 0.5;
	if (keycode == 65453)
		data->camera->zoom -= 0.5;
	if (keycode == 65429 || keycode == 65434
		|| keycode == 65430 || keycode == 65432
		|| keycode == 65436 || keycode == 65435)
		key_hook_rot(keycode, data);
	return (0);
}
