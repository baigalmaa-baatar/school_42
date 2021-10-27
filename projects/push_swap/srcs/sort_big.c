/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/27 00:05:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_big(t_stack	**stack_a)
{
	t_stack	*stack_b;
	int		median1;
	int		median2;
	int		median3;

	stack_b = NULL;
	sort_array(*stack_a, &median1, &median2, &median3);
	balance_stack(stack_a, &stack_b, INT_MIN, median1);
	while (stack_b != NULL)
		b_to_a(stack_a, &stack_b);
	balance_stack(stack_a, &stack_b, median1, median2);
	rotate_a(stack_a);
	while (stack_b != NULL)
		b_to_a(stack_a, &stack_b);
	balance_stack(stack_a, &stack_b, median2, median3);
	rotate_a(stack_a);
	while (stack_b != NULL)
		b_to_a(stack_a, &stack_b);
	balance_stack(stack_a, &stack_b, median3, INT_MAX);
	rotate_a(stack_a);
	while (stack_b != NULL)
		b_to_a(stack_a, &stack_b);
	rotate_a(stack_a);
	return (0);
}
