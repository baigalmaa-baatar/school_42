/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:11:05 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/20 15:11:07 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_get_numbers(char *str, int *stack_a)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(str); //end zogsson
	while (str[i] != '\0')
	{
		if (i % 2 == 1)
		{
			if (str[i] != ' ')
				return (0);
		}
		else
		{
			if (ft_atoi(&str[i]) >= INT_MIN && ft_atoi(&str[i]) <= INT_MAX)
				stack_a[i / 2] = ft_atoi(&str[i]);
			else
				return (0);
		}
		i++;
	}
	return (1);
}
