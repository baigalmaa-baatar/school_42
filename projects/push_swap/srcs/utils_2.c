/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:43 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 23:12:37 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *arr1, int *arr2)
{
	int	tmp;

	tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

void	do_ra(t_stack **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ra(a);
		i++;
	}
}

void	do_rra(t_stack **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rra(a);
		i++;
	}
}

t_stack	*rotate_a(t_stack **a)
{
	t_stack			*tmp;
	unsigned int	size;
	unsigned int	i;

	tmp = *a;
	size = len_list(tmp);
	i = 0;
	while (i < size && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i + 1 < size - i - 1)
	{
		do_ra(a, i + 1);
	}
	else
	{
		do_rra(a, size - i - 1);
	}
	return (*a);
}

int	balance_stack(t_stack **a, t_stack **b, int med_min, int med_max)
{
	unsigned int	i;
	unsigned int	size;

	size = len_list(*a);
	i = 0;
	while (i < size)
	{
		if ((*a)->data > med_min && (*a)->data <= med_max)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
		}
		i++;
	}
	return (0);
}
