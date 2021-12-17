/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 02:17:43 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/17 02:17:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double percent (int min, int max, int current)
{
	return ((current - min)/(max - min));
}

int	lighting(int a_point, int b_point, double percentage)
{
	return ((int)(1 - percentage) * a_point + percentage * b_point);
}

int	get_color(int a_point, int b_point, double percentage)
{
	int	r;
	int	g;
	int	b;

	if (a_point == b_point)
		return (a_point);
	r = lighting((a_point >> 16) & 0xFF, (b_point >> 16) & 0xFF, percentage);
	g = lighting((a_point >> 8) & 0xFF, (b_point >> 8) & 0xFF, percentage);
	b = lighting(a_point & 0xFF, b_point & 0xFF, percentage);
	return (r << 16 | g << 8 | b);
}
