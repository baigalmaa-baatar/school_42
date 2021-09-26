/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:05:55 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/24 15:54:09 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_val(const char *str, va_list a_list)
{
	if (str[0] == 'c')
		return (print_c(a_list));
	else if (str[0] == 's')
		return (print_str(a_list));
	else if (str[0] == 'p')
		return (print_p(a_list));
	else if (str[0] == 'd' || str[0] == 'i')
		return (print_di(a_list));
	else if (str[0] == 'u')
		return (print_u(a_list));
	else if (str[0] == 'x')
		return (print_sx(a_list));
	else if (str[0] == 'X')
		return (print_x(a_list));
	else if (str[0] == '%')
		return (print_perc());
	return (-1);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		result;
	va_list	a_list;
	int		tmp;

	va_start(a_list, input);
	result = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			tmp = print_val(&input[i + 1], a_list);
			if (-1 < tmp)
			{
				result += tmp;
				i++;
			}
		}
		else
			result += write(1, &input[i], 1);
		i++;
	}
	va_end(a_list);
	return (result);
}
