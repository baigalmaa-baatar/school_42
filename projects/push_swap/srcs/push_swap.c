/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:20 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/20 15:11:24 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_copy(int	*stack_a, int	*stack_b)
{
	int i = 0;

	while (i < 6)
	{
		stack_b[i] = stack_a[i];
		i++;
	}
}

void	ft_printf(int *stack)
{
	int i = 0;

	while(i < 10)
	{
		printf("%d\n", stack[i]);
		i++;
	}
}
void	initiliaze_stack(int *stack_a, int *stack_b)
{
	memset(stack_a, 0, 500 * sizeof(int));
	memset(stack_b, 0, 500 * sizeof(int));
}

int	sa(int len, int *stack)
{
	int	tmp;

	if (len < 2)
	{
		printf("here\n");
		return (1);
	}
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (0);
}

void	sb(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void	ss(int *stack_a, int *stack_b)
{
	sa(&stack_a[0], &stack_a[1]);
	sb(&stack_b[0], &stack_b[1]);
}

int main(int argc, char *argv[])
{
	int	stack_a[500];
	int	stack_b[500];
	int len;
	
	len = 0;
	initiliaze_stack(stack_a, stack_b);
	if (argc != 2 || ft_get_numbers(argv[1], stack_a) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	printf("before\n");
	sa(len, stack_a);
	ft_copy(stack_a, stack_b);
	// sb(&stack_b[0], &stack_b[1]);
	ss(stack_a, stack_b);
	printf("after\n");
	ft_printf(stack_b);
	ft_printf(stack_a);
}
