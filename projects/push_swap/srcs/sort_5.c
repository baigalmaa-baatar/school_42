/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:36:36 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/27 14:12:25 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	curr_is_min_5(t_stack **stack_a, t_stack *stack_b)
{
	pb(stack_a, &stack_b);
	sort_4(stack_a);
	pa(stack_a, &stack_b);
}

void	next_is_min_5(t_stack **stack_a, t_stack *stack_b)
{
	sa(stack_a);
	pb(stack_a, &stack_b);
	sort_4(stack_a);
	pa(stack_a, &stack_b);
}

void	nn_is_min_5(t_stack **stack_a, t_stack *stack_b)
{
	ra(stack_a);
	ra(stack_a);
	pb(stack_a, &stack_b);
	sort_4(stack_a);
	pa(stack_a, &stack_b);
}

void	nnn_is_min_5(t_stack **stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rra(stack_a);
	pb(stack_a, &stack_b);
	sort_4(stack_a);
	pa(stack_a, &stack_b);
}

int	sort_5(t_stack **stack_a)
{
	int		tmp1;
	int		tmp2;
	int		tmp3;
	int		min;
	t_stack	*stack_b;

	stack_b = NULL;
	min = sort_array(*stack_a, &tmp1, &tmp2, &tmp3);
	if ((*stack_a)->data == min)
		curr_is_min_5(stack_a, stack_b);
	else if ((*stack_a)->next->data == min)
		next_is_min_5(stack_a, stack_b);
	else if ((*stack_a)->next->next->data == min)
		nn_is_min_5(stack_a, stack_b);
	else if ((*stack_a)->next->next->next->data == min)
		nnn_is_min_5(stack_a, stack_b);
	else
	{
		rra(stack_a);
		pb(stack_a, &stack_b);
		sort_4(stack_a);
		pa(stack_a, &stack_b);
	}
	return (0);
}
