/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:32:45 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 22:40:07 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_array	new_array(void)
{
	t_array	result;

	result.length = 0;
	result.capacity = 0;
	result.elements = NULL;
	return (result);
}

void	array_stretch(t_array *arr)
{
	size_t	new_capacity;
	void	**new_elements;
	size_t	i;

	new_capacity = arr->capacity * 2 + 1;
	new_elements = my_malloc(new_capacity * sizeof(void *));
	i = 0;
	while (i < arr->length)
	{
		new_elements[i] = arr->elements[i];
		i++;
	}
	if (arr->elements)
		free(arr->elements);
	arr->capacity = new_capacity;
	arr->elements = new_elements;
}

void	array_append(t_array *arr, void *new_element)
{
	if (arr->length + 1 > arr->capacity)
		array_stretch(arr);
	arr->elements[arr->length] = new_element;
	arr->length++;
}

void	delete_array(t_array *arr)
{
	arr->length = 0;
	arr->capacity = 0;
	if (arr->elements)
	{
		free(arr->elements);
		arr->elements = NULL;
	}
}
