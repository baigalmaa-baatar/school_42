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

//[min width][precision][length modifier][conversion specifier]

#include "../include/ft_printf.h"

int ft_length_nbr(int nbr)
{
	int i = 0;
	if(nbr < 0)
	{
		nbr = -nbr;
		// i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

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

void print_val_di(struct s_format *format, va_list a_list)
{
	char buff[100];
	int nbr;
	int i;
	int max;
	int len;

	if (format->precision == -1)
		format->precision = 0;
	char temp_p[format->precision];
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - 1 - format->precision), '0', format->precision * sizeof(char));
	buff[99] = 0;
	i = 98;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(format->width, sizeof(temp_p)), len);
	ft_putstr(&buff[100 - 1 - max]);
}

void print_val_hhdi(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	signed char nbr;
	int i;
	int max;
	int len;
	int negative;

	negative = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));

	if (nbr < 0)
	{
		// ene hesgiig martahaas umnu zasah->(char)-128
		nbr = -nbr;
		negative = 1;
	}
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(format->width, precision), len);
	// printf("buff is : %s", buff);
	// printf("max is : %d", max);
	if(negative)
	{
		if(precision == max && precision > len) //%5.10hhd
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len) ////%10.1hhd  123
		{	
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
			// printf("buff is : %s", buff);
		}
		else //%10.1hhd
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
			// printf("max is : %d", max);
			// printf("len is : %d", len);
			// printf("buff is : |%s|", buff);

		}
	}
	// printf("buff is : |%s|", buff);
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
		// printf("buff is : |%s|", buff);

	}
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_hdi(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	short nbr;
	int i;
	int max;
	int len;
	int negative;

	negative = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));

	if (nbr < 0)
	{
		// ene hesgiig martahaas umnu zasah->(char)-128
		nbr = -nbr;
		negative = 1;
	}
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(format->width, precision), len);
	// printf("buff is : %s", buff);
	// printf("max is : %d", max);
	if(negative)
	{
		if(precision == max && precision > len) //%5.10hhd
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len) ////%10.1hhd  123
		{	
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
			// printf("buff is : %s", buff);
		}
		else //%10.1hhd
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
			// printf("max is : %d", max);
			// printf("len is : %d", len);
			// printf("buff is : |%s|", buff);

		}
	}
	// printf("buff is : |%s|", buff);
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
		// printf("buff is : |%s|", buff);

	}
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_ldi(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	long nbr;
	int i;
	int max;
	int len;
	int negative;

	negative = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));

	if (nbr < 0)
	{
		// ene hesgiig martahaas umnu zasah->(char)-128
		nbr = -nbr;
		negative = 1;
	}
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(format->width, precision), len);
	// printf("buff is : %s", buff);
	// printf("max is : %d", max);
	if(negative)
	{
		if(precision == max && precision > len) //%5.10hhd
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len) ////%10.1hhd  123
		{	
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
			// printf("buff is : %s", buff);
		}
		else //%10.1hhd
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
			// printf("max is : %d", max);
			// printf("len is : %d", len);
			// printf("buff is : |%s|", buff);

		}
	}
	// printf("buff is : |%s|", buff);
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
		// printf("buff is : |%s|", buff);

	}
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_lldi(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	long long nbr;
	int i;
	int max;
	int len;
	int negative;

	negative = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));

	if (nbr < 0)
	{
		// ene hesgiig martahaas umnu zasah->(char)-128
		nbr = -nbr;
		negative = 1;
	}
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(format->width, precision), len);
	// printf("buff is : %s", buff);
	// printf("max is : %d", max);
	if(negative)
	{
		if(precision == max && precision > len) //%5.10hhd
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len) ////%10.1hhd  123
		{	
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
			// printf("buff is : %s", buff);
		}
		else //%10.1hhd
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
			// printf("max is : %d", max);
			// printf("len is : %d", len);
			// printf("buff is : |%s|", buff);

		}
	}
	// printf("buff is : |%s|", buff);
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
		// printf("buff is : |%s|", buff);

	}
	else
		ft_putstr(&buff[100 - max]);
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
	format->width_digit = 0;
	format->precision = -1;
	format->precision_digit = 0;
	format->length = 0;
	format->length_digit = 0;
	format->specifier = 0;
}

int detect_width(char *str, struct s_format *format)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	format->width = nbr;
	// printf("the number is : %d\n", format->width);
	format->width_digit = i;
	// printf("the number digit is : %d\n", format->width_digit);
	return (format->width);
}

int detect_precision(char *str, struct s_format *format)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	format->precision = nbr;
	format->precision_digit = i;
	return (format->precision);
}

int detect_length(char *str, struct s_format *format)
{
	int i;

	i = 0;
	if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
		{
			format->length = 2;
			format->length_digit = 2;
		}
		else
		{
			format->length = 1;
			format->length_digit = 1;
		}
	}
	else if (str[i] == 'l')
	{
		i++;
		if (str[i] == 'l')
		{
			format->length = 4;
			format->length_digit = 2;
		}
		else
		{
			format->length = 3;
			format->length_digit = 1;
		}
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

int detect_specifier(char *str, struct s_format *format)
{
	int i;

	i = 0;
	if (str[i] == 'd' || str[i] == 'i')
	{
		format->specifier = 1;
	}
	else if (str[i] == 'o')
		format->specifier = 2;
	else if (str[i] == 'u')
		format->specifier = 3;
	else if (str[i] == 'x')
		format->specifier = 4;
	else if (str[i] == 'X')
		format->specifier = 5;
	else if (str[i] == 'D' || str[i] == 'O' || str[i] == 'U')
		format->specifier = 6;
	else if (str[i] == 'e' || str[i] == 'E')
		format->specifier = 7;
	else if (str[i] == 'f' || str[i] == 'F')
		format->specifier = 8;
	else if (str[i] == 'g' || str[i] == 'G')
		format->specifier = 9;
	else if (str[i] == 'a' || str[i] == 'A')
		format->specifier = 10;
	else if (str[i] == 'C')
		format->specifier = 11;
	else if (str[i] == 'c')
		format->specifier = 12;
	else if (str[i] == 'S')
		format->specifier = 13;
	else if (str[i] == 's')
		format->specifier = 14;
	else if (str[i] == 'p')
		format->specifier = 15;
	else if (str[i] == 'n')
		format->specifier = 16;
	else if (str[i] == '%')
		format->specifier = 17;
	else
		return (0);
	return (1);
}

void print_val(struct s_format *format, va_list a_list)
{
	if (format->length == 0)
	{
		if (format->specifier == 1)
		{
			print_val_di(format, a_list);
		}
		else if (format->specifier == 2 || format->specifier == 3 || \
		format->specifier == 4 || format->specifier == 5)
		{
			// print_val_ouxX(&format, a_list);
		}
		else if (format->specifier == 16)
		{
			// print_val_n(&format, a_list);
		}
	}
	if (format->length == 1)
	{
		if (format->specifier == 1)
		{
			// printf("here");
			print_val_hdi(format, a_list);
		}
		else if (format->specifier == 2 || format->specifier == 3 || \
		format->specifier == 4 || format->specifier == 5)
		{
			// print_val_hhouxX(&format, a_list);
		}
		else if (format->specifier == 16)
		{
			// print_val_hhn(&format, a_list);
		}
	}
	if (format->length == 2)
	{
		if (format->specifier == 1)
		{
			// printf("here\n");
			print_val_hhdi(format, a_list);
		}
		else if (format->specifier == 2 || format->specifier == 3 || \
		format->specifier == 4 || format->specifier == 5)
		{
			// print_val_hhouxX(&format, a_list);
		}
		else if (format->specifier == 16)
		{
			// print_val_hhn(&format, a_list);
		}
	}
	if (format->length == 3)
	{
		if (format->specifier == 1)
		{
			// printf("here\n");
			print_val_ldi(format, a_list);
		}
		else if (format->specifier == 2 || format->specifier == 3 || \
		format->specifier == 4 || format->specifier == 5)
		{
			// print_val_hhouxX(&format, a_list);
		}
		else if (format->specifier == 16)
		{
			// print_val_hhn(&format, a_list);
		}
	}
	if (format->length == 4)
	{
		if (format->specifier == 1)
		{
			// printf("here\n");
			print_val_lldi(format, a_list);
		}
		else if (format->specifier == 2 || format->specifier == 3 || \
		format->specifier == 4 || format->specifier == 5)
		{
			// print_val_hhouxX(&format, a_list);
		}
		else if (format->specifier == 16)
		{
			// print_val_hhn(&format, a_list);
		}
	}
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
			if (detect_width((char *)&input[i], &format) != 0)
			{
				i += format.width_digit;
			}
			// printf("the width digit is : %d\n", format.width_digit);

			// printf("the input is : %s\n", &input[i]);
			if(input[i] == '.')
			{
				i++;
				detect_precision((char *)&input[i], &format);
				i += format.precision_digit;
			}
			if (detect_length((char *)&input[i], &format) != 0)
			{
				i += format.length_digit;
			}
			if (detect_specifier((char *)&input[i], &format) != 0)
			{
				// i++;
			}
			print_val(&format, a_list);
			// printf("the input is : %s\n", &input[i]);
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
	printf("%d\n", 0);
	ft_printf("%d\n", 0);
	printf("%d\n", 10);
	ft_printf("%d\n", 10);
	printf("%d\n, %d\n", 10, 20);
	ft_printf("%d\n, %d\n", 10, 20);
	printf("%d%d%d%d\n", 10, 20, 30, 5);
	ft_printf("%d%d%d%d\n", 10, 20, 30, 5);
	printf("%d %d\n", 2147483647, (int)-2147483648);
	ft_printf("%d %d\n", 2147483647, (int)-2147483648);
	printf("42 - 84 is %d\n", -42);
	ft_printf("42 - 84 is %d\n", -42);
	printf("%d C is the lowest temperature in the universe\n", -273);
	ft_printf("%d C is the lowest temperature in the universe\n", -273);
	printf("%dxC is the lowest temperature in the universe\n", -273);
	ft_printf("%dxC is the lowest temperature in the universe\n", -273);
	printf("%dsC is the lowest temperature in the universe\n", -273);
	ft_printf("%dsC is the lowest temperature in the universe\n", -273);
	printf("%dpC is the lowest temperature in the universe\n", -273);
	ft_printf("%dpC is the lowest temperature in the universe\n", -273);
	
	printf("---------------------------------------------------------------");
	printf("%u\n", 42);
	ft_printf("%u\n", 42);
	printf("%u\n", 0);
	ft_printf("%u\n", 0);
	printf("%u\n", 2147483647);
	ft_printf("%u\n", 2147483647);
	printf("%u\n", (unsigned int)2147483648);
	ft_printf("%u\n", (unsigned int)2147483648);
	printf("%u\n", (unsigned int)3147983649);
	ft_printf("%u\n", (unsigned int)3147983649);
	printf("%u\n", (unsigned int)4294967295);
	ft_printf("%u\n", (unsigned int)4294967295);
	printf("%u to the power of %u is %u\n", 2, 32, (unsigned int)4294967295);
	ft_printf("%u to the power of %u is %u\n", 2, 32, (unsigned int)4294967295);
	printf("%u%u%u%u\n", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);
	ft_printf("%u%u%u%u\n", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);

	printf("22) Vrai PRINTF : |%10hhd|\n", (char)-42);
	ft_printf("22) Mon PRINTF  : |%10hhd|\n", (char)-42);
	printf("27) Vrai PRINTF : |%1.1hhd|\n", (char)-20);
	ft_printf("27) Mon PRINTF  : |%1.1hhd|\n", (char)-20);
	printf("33) Vrai PRINTF : |%2hhd|\n", (char)-20);
	ft_printf("33) Mon PRINTF  : |%2hhd|\n", (char)-20);
	printf("34) Vrai PRINTF : |%.2hhd|\n", (char)-20);
	ft_printf("34) Mon PRINTF  : |%.2hhd|\n", (char)-20);
	printf("35) Vrai PRINTF : |%2hhd|\n", (char)-1);
	ft_printf("35) Mon PRINTF  : |%2hhd|\n", (char)-1);
	printf("49) Vrai PRINTF : |%.hhd|\n", (char)0);
	ft_printf("49) Mon PRINTF  : |%.hhd|\n", (char)0);

	return 0;
}
