/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:16:47 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 01:36:39 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	xaxis_rot(int *y, int *z, double theta)
{
	int	prev_y;
	int	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(theta) + prev_z * sin(theta);
	*z = prev_z * cos(theta) - prev_y * sin(theta);
}

void	yaxis_rot(int *x, int *z, double theta)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(theta) + prev_z * sin(theta);
	*z = prev_z * cos(theta) - prev_x * sin(theta);
}

void	zaxis_rot(int *x, int *y, double theta)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
}
