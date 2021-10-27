/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_or_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:13:44 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 23:50:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_max(t_stack **stack_b, unsigned int size,
	unsigned int *min_pos, unsigned int *max_pos)
{
	t_stack			*tmp;
	int				min;
	int				max;
	unsigned int	i;

	tmp = *stack_b;
	min = (*stack_b)->data;
	max = (*stack_b)->data;
	i = 0;
	while (i < size)
	{
		if (tmp->data < min)
		{
			*min_pos = i;
			min = tmp->data;
		}
		if (tmp->data > max)
		{
			*max_pos = i;
			max = tmp->data;
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	get_flags(unsigned int *pos, int *rra_flag,
	int *rb_rrb_flag, unsigned int size)
{
	unsigned int	position;

	position = ft_min(ft_min(pos[0], pos[1]),
			ft_min(size - pos[0], size - pos[1]));
	if (position == pos[0])
	{
		*rra_flag = 0;
		*rb_rrb_flag = 0;
	}
	else if (position == (size - pos[0]))
	{
		*rra_flag = 0;
		*rb_rrb_flag = 1;
	}
	else if (position == pos[1])
	{
		*rra_flag = 1;
		*rb_rrb_flag = 0;
	}
	else if (position == (size - pos[1]))
	{
		*rra_flag = 1;
		*rb_rrb_flag = 1;
	}
	return (position);
}

int	find_max_or_min(t_stack **stack_b, int *rra_flag, int *rb_rrb_flag)
{
	unsigned int	size;
	unsigned int	res;
	unsigned int	pos[2];
	unsigned int	min_pos;
	unsigned int	max_pos;

	min_pos = 0;
	max_pos = 0;
	size = len_list(*stack_b);
	get_min_max(stack_b, size, &min_pos, &max_pos);
	pos[0] = min_pos;
	pos[1] = max_pos;
	res = get_flags(pos, rra_flag, rb_rrb_flag, size);
	return (res);
}
