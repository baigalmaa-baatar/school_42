/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:20 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/28 15:19:32 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_elem(int data)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (0);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_stack_clear(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	while (current)
	{
		current->data = 0;
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	convert_stack(t_stack **stack_a, int size, long long *nbrs)
{
	int		i;
	t_stack	*tmp;

	tmp = create_elem(nbrs[0]);
	*stack_a = tmp;
	i = 1;
	while (i < size)
	{
		tmp->next = create_elem(nbrs[i]);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	sort_stack(t_stack **stack_a, int size)
{
	if (size <= 1)
		return (0);
	else if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a);
	else if (size == 5)
		sort_5(stack_a);
	else if (size <= 50 && size >= 6)
		sort_mid(stack_a);
	else
		sort_big(stack_a);
	return (1);
}

int	main(int argc, char *argv[])
{
	int			size;
	t_stack		*stack_a;
	long long	nbrs[10000];

	stack_a = NULL;
	if (argc <= 1)
		return (0);
	size = get_numbers(argc, argv, nbrs);
	if (!size)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	convert_stack(&stack_a, size, nbrs);
	if (!check_already_sorted(stack_a))
	{
		ft_stack_clear(stack_a);
		return (0);
	}
	if (!sort_stack(&stack_a, size))
		return (0);
	ft_print(stack_a);
	ft_stack_clear(stack_a);
	return (0);
}
