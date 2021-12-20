/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:13:11 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:13:14 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_hook(int button, int x, int y, t_image *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->camera->zoom += 0.5;
	if (button == 5)
		data->camera->zoom -= 0.5;
	return (0);
}
