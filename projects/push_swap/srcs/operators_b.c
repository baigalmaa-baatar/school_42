/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:53:50 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:59:21 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sb(t_stack **list)
{
	t_stack	*tmp_elem;

	if (!((*list)->next))
		return (1);
	tmp_elem = *list;
	*list = (*list)->next;
	tmp_elem->next = (*list)->next;
	(*list)->next = tmp_elem;
	write(1, "sb\n", 3);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_elem;

	if (!*a)
		return (1);
	if ((*a)->next)
	{
		tmp_elem = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp_elem;
	}
	else
	{
		tmp_elem = *a;
		(*a)->next = *b;
		*b = *a;
		*a = NULL;
	}
	write (1, "pb\n", 3);
	return (0);
}

int	rb(t_stack **b)
{
	t_stack	*tmp_elem;
	t_stack	*root;

	if (!*b)
		return (1);
	root = *b;
	tmp_elem = (*b)->next;
	if ((*b)->next)
	{
		while ((*b)->next)
		{
			*b = (*b)->next;
		}
		(*b)->next = root;
		root->next = NULL;
		*b = tmp_elem;
		write(1, "rb\n", 3);
		return (0);
	}
	write (1, "rb\n", 3);
	return (1);
}

int	rrb(t_stack **b)
{
	t_stack	*tmp_elem;
	t_stack	*root;

	if (!*b)
		return (1);
	root = *b;
	if ((*b)->next)
	{
		while ((*b)->next->next)
		{
			*b = (*b)->next;
		}
		tmp_elem = (*b)->next;
		(*b)->next = NULL;
		tmp_elem->next = root;
		*b = tmp_elem;
		write(1, "rrb\n", 4);
		return (0);
	}
	write (1, "rrb\n", 4);
	return (1);
}
