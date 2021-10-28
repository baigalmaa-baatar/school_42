/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:15:42 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 23:59:31 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_to_a(t_stack **stack_b, int *rb_rrb_flag, unsigned int w_pos)
{
	if (!(*rb_rrb_flag))
	{
		while (w_pos > 0)
		{
			rb(stack_b);
			w_pos--;
		}
	}
	else
	{
		while (w_pos > 0)
		{
			rrb(stack_b);
			w_pos--;
		}
	}
	return (0);
}

int	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	w_pos;
	int				*rra_flag;
	int				*rb_rrb_flag;

	rra_flag = malloc(sizeof(int) * 1);
	rb_rrb_flag = malloc(sizeof(int) * 1);
	if (!rra_flag || !rb_rrb_flag)
		return (0);
	*rra_flag = 1;
	*rb_rrb_flag = 1;
	w_pos = 0;
	w_pos = find_max_or_min(stack_b, rra_flag, rb_rrb_flag);
	push_to_a(stack_b, rb_rrb_flag, w_pos);
	pa (stack_a, stack_b);
	if (!(*rra_flag))
		ra(stack_a);
	free (rra_flag);
	free (rb_rrb_flag);
	return (0);
}
