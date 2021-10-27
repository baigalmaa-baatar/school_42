/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:59:36 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/27 14:03:35 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
	return (0);
}

void	curr_is_bigger(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ra(stack_a);
		sort_2(stack_a);
	}
	else
		sa(stack_a);
}

int	curr_is_smaller(t_stack **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		if ((*stack_a)->next->data < (*stack_a)->next->next->data)
			return (0);
		else
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	else
		rra(stack_a);
	return (1);
}

int	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		curr_is_bigger(stack_a);
	else if ((*stack_a)->data < (*stack_a)->next->data)
		curr_is_smaller(stack_a);
	return (1);
}
