/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:05:17 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 21:21:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_array(t_stack *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->data;
		stack = stack->next;
		i++;
	}
	return (0);
}

int	find_median(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				swap(&arr[j], &arr[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_array(t_stack *a, int *median1, int *median2, int *median3)
{
	int		size;
	int		*arr;
	int		min;

	size = len_list(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (1);
	get_array(a, arr);
	find_median(arr, size);
	min = arr[0];
	*median1 = arr[size / 4];
	*median2 = arr[size / 2];
	*median3 = arr[(size / 4) * 3];
	free(arr);
	return (min);
}
