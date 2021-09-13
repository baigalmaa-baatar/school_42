/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:05:55 by bbaatar           #+#    #+#             */
/*   Updated: 2021/08/12 11:22:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//testers:
// https://github.com/Tripouille/printfTester
//https://github.com/paulo-santana/ft_printf_testers

#include "../include/ft_printf.h"

void initialize_format(struct s_format *format)
{
	format->width = 0;
	format->width_digit = 0;
	format->precision = -1;
	format->precision_digit = 0;
	format->specifier = 0;
}

int print_val(char *str, struct s_format *format, va_list a_list)
{
	int num_chars;

	num_chars = 0;
	if (str[0] == 'c')
		num_chars = print_c(format, a_list);
	else if (str[0] == 's')
		num_chars = print_str(format, a_list);
	else if (str[0] == 'p')
		num_chars = print_p(format, a_list);
	else if (str[0] == 'd' || str[0] == 'i')
		num_chars = print_di(format, a_list);
	else if (str[0] == 'u')
		num_chars = print_u(format, a_list);
	else if (str[0] == 'x')
		num_chars = print_sx(format, a_list);
	else if (str[0] == 'X')
		num_chars = print_X(format, a_list);
	else if (str[0] == '%')
		num_chars = print_perc();
	else
		return (0);
	return (num_chars);
}

int ft_printf(const char *input, ...)
{
	int i;
	int k;
	int num_char;
	int sum_char;
	va_list a_list;
	struct s_format format;
	const char *str_in;

	str_in = ft_strdup(input);
	initialize_format(&format);
	va_start(a_list, input);
	num_char = 0;
	sum_char = 0;
	i = 0;
	k = 0;
	while (str_in[i] != '\0')
	{
		if (str_in[i] == '%')
		{
			i++;
			if (detect_width((char *)&str_in[i], &format) != 0)
			{
				i += format.width_digit;
			}
			if(str_in[i] == '.')
			{
				i++;
				detect_precision((char *)&str_in[i], &format);
				i += format.precision_digit;
			}
			num_char = print_val((char *)&str_in[i], &format, a_list);
			sum_char += num_char;
		}
		else
		{
			write(1, (const void *)&str_in[i], 1);
			k++;
		}
		i++;
	}

	sum_char += k;
	va_end(a_list);
	free((char *)str_in);
	return (sum_char);
}

int main()
{
   	printf("%s %s \n", "18", "-20");
	ft_printf("%s %s \n", "18", "-20");
	printf("%p %p \n", "18", "-20");
   	ft_printf("%p %p \n", "18", "-20");
}