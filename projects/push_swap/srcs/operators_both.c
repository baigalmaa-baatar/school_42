/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:19:26 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:52:14 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	return (0);
}
