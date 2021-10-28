/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:51:05 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 17:02:53 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_already_sorted(t_stack *ref_stack)
{
	t_stack	*stack;

	stack = ref_stack;
	while (stack != NULL && stack->next)
	{
		if (stack->data > stack->next->data)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_max(unsigned int nbr1, unsigned int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

int	ft_min(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

void	ft_print(t_stack *ref_list)
{
	t_stack	*list;

	list = ref_list;
	while (list)
	{
		// printf("%d\n", list->data);
		list = list->next;
	}
}

unsigned int	len_list(t_stack *ref_list)
{
	t_stack			*list;
	unsigned int	len;

	if (!ref_list)
		return (0);
	list = ref_list;
	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}
