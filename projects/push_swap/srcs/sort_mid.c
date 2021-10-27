/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:20:36 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/27 13:35:09 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_mid(t_stack	**stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (*stack_a != NULL)
	{
		pb(stack_a, &stack_b);
	}
	while (stack_b != NULL)
	{
		b_to_a(stack_a, &stack_b);
	}
	rotate_a(stack_a);
	return (0);
}
