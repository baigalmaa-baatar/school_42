/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:53:43 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 16:57:22 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack **list)
{
	t_stack	*tmp_elem;

	if (!((*list)->next))
		return (1);
	tmp_elem = *list;
	*list = (*list)->next;
	tmp_elem->next = (*list)->next;
	(*list)->next = tmp_elem;
	write(1, "sa\n", 3);
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_elem;

	if (!*b)
		return (1);
	if ((*b)->next)
	{
		tmp_elem = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp_elem;
	}
	else
	{
		tmp_elem = *b;
		(*b)->next = *a;
		*a = *b;
		*b = NULL;
	}
	write (1, "pa\n", 3);
	return (0);
}

int	ra(t_stack **a)
{
	t_stack	*tmp_elem;
	t_stack	*root;

	if (!*a)
		return (1);
	root = *a;
	tmp_elem = (*a)->next;
	if ((*a)->next)
	{
		while ((*a)->next)
		{
			*a = (*a)->next;
		}
		(*a)->next = root;
		root->next = NULL;
		*a = tmp_elem;
		write(1, "ra\n", 3);
		return (0);
	}
	write (1, "ra\n", 3);
	return (1);
}

int	rra(t_stack **a)
{
	t_stack	*tmp_elem;
	t_stack	*root;

	if (!*a)
		return (1);
	root = *a;
	if ((*a)->next)
	{
		while ((*a)->next->next)
		{
			*a = (*a)->next;
		}
		tmp_elem = (*a)->next;
		(*a)->next = NULL;
		tmp_elem->next = root;
		*a = tmp_elem;
		write(1, "rra\n", 4);
		return (0);
	}
	write(1, "rra\n", 4);
	return (1);
}
