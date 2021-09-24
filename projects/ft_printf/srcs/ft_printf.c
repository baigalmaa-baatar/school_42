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

void	initialize_format(struct s_format *format)
{
	format->width = 0;
	format->width_digit = 0;
	format->precision = -1;
	format->precision_digit = 0;
	format->flag_prec = 0;
	format->specifier = 0;
	format->negative = 0;
	format->base = "0123456789";
	format->base_nbr = 10;
}

int	print_val(char *str, struct s_format *format, va_list a_list)
{
	int	num_chars;

	num_chars = 0;
	if (str[0] == 'c')
		num_chars = print_c(format, a_list);
	else if (str[0] == 's')
		num_chars = print_str(format, a_list);
	else if (str[0] == 'p')
		num_chars = print_p(a_list);
	else if (str[0] == 'd' || str[0] == 'i')
		num_chars = print_di(format, a_list);
	else if (str[0] == 'u')
		num_chars = print_u(format, a_list);
	else if (str[0] == 'x')
		num_chars = print_sx(format, a_list);
	else if (str[0] == 'X')
		num_chars = print_x(format, a_list);
	else if (str[0] == '%')
		num_chars = print_perc();
	else
		return (0);
	return (num_chars);
}

int	detect_width_and_precision(char *str, struct s_format *format,
		int *i, va_list *a_list)
{
	int	sum_char;

	sum_char = 0;
	if (str[*i] == '%')
	{
		(*i)++;
		if (detect_width(&str[*i], format) != 0)
			*i += format->width_digit;
		if (str[*i] == '.')
		{
			(*i)++;
			detect_precision(&str[*i], format);
			*i += format->precision_digit;
		}
		sum_char += print_val(&str[*i], format, *a_list);
	}
	else
	{
		write(1, (const void *)&str[*i], 1);
		sum_char++;
	}
	(*i)++;
	return (sum_char);
}

int	ft_printf(const char *input, ...)
{
	int				i;
	int				sum_char;
	va_list			a_list;
	struct s_format	format;
	const char		*str_in;

	str_in = ft_strdup(input);
	va_start(a_list, input);
	sum_char = 0;
	i = 0;
	while (str_in[i] != '\0')
	{
		initialize_format(&format);
		sum_char += detect_width_and_precision((char *)str_in, &format,
				&i, &a_list);
	}
	va_end (a_list);
	free((char *)str_in);
	return (sum_char);
}
