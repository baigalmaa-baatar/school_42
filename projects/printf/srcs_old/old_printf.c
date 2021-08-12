/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:05:55 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/16 11:06:16 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	unsigned int nbr_ui;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_ui = (unsigned int)nbr;
	if (nbr_ui > 9)
	{
		ft_putnbr(nbr_ui / 10);
	}
	ft_putchar(nbr_ui % 10 + '0');
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

initialize_format(t_format format)
{
	format.minus = 0;
	format.plus = 0;
	format.space = 0;
	format.zero = 0;
	format.apostrophe = 0;
	format.hash = 0;
	format.width = 0;
	format.precision = 0;
	format.length = 0;
	format.type = 0;
}

int detect_flag(char *str, t_format format, va_list a_list)
{
	int i;

	i = 0;
	if (str[i] == '-')
		format.minus = 1;
	else if (str[i] == '+')
		format.plus = 1;
	else if (str[i] == ' ')
		format.space = 1;
	else if (str[i] == '0')
		format.zero = 1;
	else if (str[i] == '\'')
		format.apostrophe = 1;
	else if (str[i] == '#')
		format.hash = 1;
	else
		return (0);
	return (1);
}

int detect_length(char *str, t_format format, va_list a_list)
{
	int i;

	i = 0;
	if (str[i] == 'h')
	{
		if (str[i++] == 'h')
			format.length = 1;
		format.length = 2;
	}
	if (str[i] == 'l')
	{
		if (str[i++] == 'l')
			format.length = 4;
		format.length = 3;
	}	
	else if (str[i] == 'j')
		format.length = 5;
	else if (str[i] == 't')
		format.length = 6;
	else if (str[i] == 'z')
		format.length = 7;
	else if (str[i] == 'q')
		format.length = 8;
	else
		return (0);
	return (1);
}

int detect_type(char *str, t_format format, va_list a_list)
{
	int i;

	i = 0;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		format.type = 1;
	if (str[i] == 'D' || str[i] == 'O' || str[i] == 'U')
		format.type = 2;
	if (str[i] == 'e' || str[i] == 'E')
		format.type = 3;
	if (str[i] == 'f' || str[i] == 'F')
		format.type = 4;
	if (str[i] == 'g' || str[i] == 'G')
		format.type = 5;
	if (str[i] == 'a' || str[i] == 'A')
		format.type = 6;
	if (str[i] == 'C')
		format.type = 7;
	if (str[i] == 'c')
		format.type = 8;
	if (str[i] == 'S')
		format.type = 9;
	if (str[i] == 's')
		format.type = 10;
	if (str[i] == 'p')
		format.type = 11;
	if (str[i] == 'n')
		format.type = 12;
	if (str[i] == '%')
		format.type = 13;
	if (str[i] == 'o')
		format.type = 14;
}

//%[flags][width][.precision][length]type
//%-10.05f float
//%-10lld  long long

printf_val(char *str, t_format format, va_list a_list)
{
	//flags

	// For o conversions, the precision of the number is increased to force the first character of the output string to a zero.
	if (format.hash && format.type == 14)
		write(1, '0', 1);
	// For x and X conversions, a non-zero result has the string `0x' (or `0X' for X conversions) prepended to it.		
	if (format.hash && format.type == 14)
				
}

int ft_printf(const char *input, ...)
{
	int i;
	int k;
	char *flag_res;
	va_list a_list;
	t_format format;

	initialize_format(format);
	flag_res = (char *)malloc(100);
	if (!flag_res)
		return (-1);
	va_start(a_list, input);
	i = 0;
	k = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			
			if(detect_flag((char *)&input[i++], format, a_list))
				i++;
			while(input[i] >= '0' && input[i] <= '9')
			{
				format.width = format.width * 10 + input[i];
				i++;
			}
			if (input[i] == '.')
				{
					i++;
					while(input[i] >= '0' && input[i] <= '9')
					{
						format.precision = format.precision * 10 + input[i];
						i++;
					}
				}
			if(detect_length((char *)&input[i++], format, a_list))
				i++;
			detect_type((char *)&input[i++], format, a_list);
			print_val((char *)&input[i++], format, a_list);
		}
		else
		{
			write(1, (const void *)&input[i], 1);
			k++;
		}
		i++;
	}
	va_end(a_list);
	return (0);
}

int main()
{
	// For o conversions, the precision of the number is increased to force the first character of the output string to a zero.
	// For x and X conversions, a non-zero result has the string `0x' (or `0X' for X conversions) prepended to it.
	// For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows).
	// For g and G conversions, trailing zeros are not removed from the result as they would otherwise be.
	
	
	// ft_printf("hello %s %d mjjfd %c ijj\n", "TEST1", 123, 42);
	printf("this is the result : %#o\n", 34);
	// printf("this is the result : %#x\n", 34);
	// printf("this is the result : %#10.5o\n", 34);
	// printf("this is the result : %2$d %2$#x; %1$d %1$#x",16,17);
	// printf("%*d\n", 5, 10);
	

	// printf("this is the result : %#.5o\n", 34);
	// printf("this is the result : %#5o\n", 34);
	// printf("this is the result : %#8.5o\n", 34);
	// printf("this is the result : %#ho\n", (unsigned short)34);
	// printf("this is the result : %#5hho\n", (unsigned char)34);
	// printf("this is the result : %#lo\n", (unsigned long)1);
	// printf("this is the result : %#hhX\n", (unsigned char)34);
	// printf("this is the result : %#a\n", 1);
    
	return 0;
}

