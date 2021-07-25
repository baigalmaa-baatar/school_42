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

void ft_putnbr_short(short nbr)
{
	unsigned short nbr_us;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_us = (unsigned short)nbr;
	if (nbr_us > 9)
	{
		ft_putnbr(nbr_us / 10);
	}
	ft_putchar(nbr_us % 10 + '0');
}

void ft_putnbr_char(signed char nbr)
{
	signed char nbr_ch;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * (-1);
	}
	nbr_ch = (unsigned char)nbr;
	if (nbr_ch > 9)
	{
		ft_putnbr(nbr_ch / 10);
	}
	ft_putchar(nbr_ch % 10 + '0');
}

void	ft_putnbr_oct(long long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 8)
		ft_putnbr_oct(nbr / 8);
	ft_putchar("01234567"[nbr % 8]);
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

void initialize_format(struct s_format *format)
{
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->zero = 0;
	format->apostrophe = 0;
	format->hash = 0;
	format->width = 0;
	format->precision = 0;
	format->length = 0;
	format->type = 0;
}

int detect_precistion(char *str, struct s_format *format)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10 + str[i];
		i++;
	}
	//("%.10hd", 100)
	
	if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
			format->length = 1;
		format->length = 2;
		i--;
	}
	if (str[i] == 'l')
	{
		if (str[i++] == 'l')
			format->length = 4;
		format->length = 3;
	}	
	else if (str[i] == 'j')
		format->length = 5;
	else if (str[i] == 't')
		format->length = 6;
	else if (str[i] == 'z')
		format->length = 7;
	else if (str[i] == 'q')
		format->length = 8;
	else
		return (0);
	return (1);
}

int detect_length(char *str, struct s_format *format)
{
	int i;

	i = 0;
	if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
			format->length = 1;
		format->length = 2;
		i--;
	}
	if (str[i] == 'l')
	{
		if (str[i++] == 'l')
			format->length = 4;
		format->length = 3;
	}	
	else if (str[i] == 'j')
		format->length = 5;
	else if (str[i] == 't')
		format->length = 6;
	else if (str[i] == 'z')
		format->length = 7;
	else if (str[i] == 'q')
		format->length = 8;
	else
		return (0);
	return (1);
}

int detect_type(char *str, struct s_format *format)
{
	int i;

	i = 0;
	if (str[i] == 'd' || str[i] == 'i')
		format->type = 1;
	else if (str[i] == 'o')
		format->type = 2;
	else if (str[i] == 'u')
		format->type = 3;
	else if (str[i] == 'x')
		format->type = 1;
	else if (str[i] == 'X')
		format->type = 1;
	else if (str[i] == 'D' || str[i] == 'O' || str[i] == 'U')
		format->type = 2;
	else if (str[i] == 'e' || str[i] == 'E')
		format->type = 3;
	else if (str[i] == 'f' || str[i] == 'F')
		format->type = 4;
	else if (str[i] == 'g' || str[i] == 'G')
		format->type = 5;
	else if (str[i] == 'a' || str[i] == 'A')
		format->type = 6;
	else if (str[i] == 'C')
		format->type = 7;
	else if (str[i] == 'c')
		format->type = 8;
	else if (str[i] == 'S')
		format->type = 9;
	else if (str[i] == 's')
		format->type = 10;
	else if (str[i] == 'p')
		format->type = 11;
	else if (str[i] == 'n')
		format->type = 12;
	else if (str[i] == '%')
		format->type = 13;
	else
		return (0);
	return (1);
}

//%[flags][width][.precision][length]type
//%-10.05f float
//%-10lld  long long

void print_val(struct s_format *format, va_list a_list)
{

	if (format->type == 1)
	{
		if(format->length == 2)
		{
			short sh = va_arg(a_list, int);
			ft_putnbr_short(sh);
		}
		else if(format->length == 1)
		{
			signed char sc = va_arg(a_list, int);
			ft_putnbr_char(sc);
		}
		else
			ft_putnbr(va_arg(a_list, int));
	}
	if (format->type == 2)
		ft_putnbr_oct(va_arg(a_list, int));
}

int ft_printf(const char *input, ...)
{
	int i;
	int k;
	char *flag_res;
	va_list a_list;
	struct s_format format;

	initialize_format(&format);
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
			i++;
			if(input[i] == '.')
			{
				i++;
				detect_precision((char *)&input[i], &format);
				i++;
			}
			if (!detect_length((char *)&input[i], &format))
			{
				// printf("input length:%s\n", &input[i]);
				i++;
			}
			if (!detect_type((char *)&input[i], &format))
			{
				// printf("input type :%s\n", &input[i]);
				i++;
			}
			print_val(&format, a_list);
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
	// ft_printf("this is the result : %d\n", 1234);
	// printf("standard : %hd\n", (char)42);
	// ft_printf("mine  : %hd\n", (char)42);

	// printf("%hd\n", (short)32767);
	// ft_printf("%hd", (short)32767);

	printf("07) Vrai PRINTF : |%.10d|\n", 100);
	ft_printf("07) Mon PRINTF  : |%.10d|\n", 100);

	return 0;
}
