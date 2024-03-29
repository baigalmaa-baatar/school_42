/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:15:25 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:33:37 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_camera	*angle_init(void)
{
	t_camera	*camera;

	camera = (t_camera *) malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	camera->thetax = 0;
	camera->thetay = 0;
	camera->thetaz = 0;
	camera->depth = 1;
	camera->zoom = 40;
	camera->move_x = 0;
	camera->move_y = 0;
	return (camera);
}
