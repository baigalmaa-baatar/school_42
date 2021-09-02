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
//ToDo
//1. %.ld(long) geh metiig zasah.
//2. printf_val_lu, print_val_llu g duusgaagui baigaa.
//3. 

#include "../include/ft_printf.h"

size_t	ft_strlen(const	char	*str)
{
	size_t	len;

	len = 0;
	if (str[0] == '\0')
		return (len);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int ft_length_nbr(long long nbr)
{
	int i = 0;

	if (!nbr)
		return (1);
	else
	{
		if(nbr < 0)
			nbr = -nbr;
		while (nbr > 0)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
}
int ft_length_o(unsigned int nbr)
{
	int i = 0;

	if (!nbr)
		return (1);
	else
	{
		if(nbr < 0)
			nbr = -nbr;
		while (nbr > 0)
		{
			nbr /= 8;
			i++;
		}
		return (i);
	}
}

int ft_length_X(unsigned int nbr)
{
	int i = 0;

	if (!nbr)
		return (1);
	else
	{
		if(nbr < 0)
			nbr = -nbr;
		while (nbr > 0)
		{
			nbr /= 16;
			i++;
		}
		return (i);
	}
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
	int precision;
	char buff[100];
	int i;
	int max;
	int len;
	int negative;
	int nbr;
	// int i_nbr;
	// short s_nbr;
	// signed char ch_nbr;
	// long l_nbr;
	// long long ll_nbr;

	// if (format->length == 0)
	// 	i_nbr = va_arg(a_list, int);
	// else if (format->length == 1)
	// 	s_nbr = va_arg(a_list, int);
	// else if (format->length == 2)
	// 	ch_nbr = va_arg(a_list, int);
	// else if (format->length == 3)
	// 	l_nbr = va_arg(a_list, int);
	// else if (format->length == 4)
	// 	ll_nbr = va_arg(a_list, int);
	nbr = va_arg(a_list, int);
	negative = 0;
	buff[99] = '\0';
	i = 99;
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
		buff[i] = '0';
	else
	{
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
	}
	// printf("buff is : %s", buff);
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
	// printf("max is : %d", max);
	// printf("len is : %d", len);
	// printf("buff is : %s", buff);

	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
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
	if (!nbr)
		buff[i] = '0';
	else
	{
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
	}
	// printf("buff is : %s", buff);
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
	// printf("max is : %d", max);
	// printf("len is : %d", len);
	// printf("buff is : %s", buff);

	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
		ft_putstr(&buff[100 - max]);

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
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr((long long)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else if (nbr == -128)
	{
		memset(buff + 96, '-', sizeof(char));
		memset(buff + 97, '1', sizeof(char));
		memset(buff + 98, '2', sizeof(char));
		memset(buff + 99, '8', sizeof(char));
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	// printf("buff is : %s", buff);
	max = ft_max(ft_max(format->width, precision), len);
	// printf("buff is : %s", buff);
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
		}
		else 
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
			// printf("buff is : %s", buff);

		}
	}
	// printf("max is : %d", max);
	// printf("len is : %d", len);
	// printf("buff is : %s", buff);
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else if (nbr == -128) //%10.1hhd
	{
			ft_putstr(&buff[96]);
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
	nbr = va_arg(a_list, int);
	negative = 0;
	buff[99] = '\0';
	i = 99;
	
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
		buff[i] = '0';
	else
	{
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
	}
	// printf("buff is : %s", buff);
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
	// printf("max is : %d", max);
	// printf("len is : %d", len);
	// printf("buff is : %s", buff);

	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
		ft_putstr(&buff[100 - max]);

}
void print_val_lldi(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	long nbr;
	
	int i;
	int max;
	int len;
	int negative;
	nbr = va_arg(a_list, int);
	negative = 0;
	buff[99] = '\0';
	i = 99;
	
	len = ft_length_nbr(nbr);
	if (format->precision == -1)
		precision = 0;
	else 
		precision = format->precision;
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
		buff[i] = '0';
	else
	{
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
	}
	// printf("buff is : %s", buff);
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
	// printf("max is : %d", max);
	// printf("len is : %d", len);
	// printf("buff is : %s", buff);

	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
		ft_putstr(&buff[100 - max]);

}

void print_val_u(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned int nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr((long long)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
		ft_putstr(&buff[100 - 1 - max]);
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_hu(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned short nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr((long long)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
		ft_putstr(&buff[100 - 1 - max]);
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_hhu(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned char nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_nbr((long long)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
		ft_putstr(&buff[100 - 1 - max]);
	else
		ft_putstr(&buff[100 - max]);
}

void print_val_o(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned int nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_o((unsigned int)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	// printf("nbr is : %u\n", nbr);
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = "01234567"[nbr % 8];
			nbr /= 8;
			i--;
		}
	}
	// printf("buff is : %s\n", buff);
	max = ft_max(ft_max(format->width, precision), len);
	// printf("max is : %d\n", max);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
	{
		ft_putstr(&buff[100 - max]);
	}
}

void print_val_sx(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned int nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_X((unsigned int)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	// printf("nbr is : %u\n", nbr);
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = "0123456789abcdef"[nbr % 16];
			nbr /= 16;
			i--;
		}
	}
	// printf("buff is : %s\n", buff);
	max = ft_max(ft_max(format->width, precision), len);
	// printf("max is : %d\n", max);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
	{
		ft_putstr(&buff[100 - max]);
	}
}

void print_val_X(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	unsigned int nbr;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	nbr = va_arg(a_list, int);
	len = ft_length_X((unsigned int)nbr);
	if (format->precision == -1)
		precision = 0;
	else
	{ 
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - precision), '0', precision * sizeof(char));
	// printf("nbr is : %u\n", nbr);
	if (!nbr)
	{
		if (flag_prec)
			buff[i] = '\0';
		else
			buff[i] = '0';
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			negative = 1;
		}
		while(nbr > 0)
		{
			buff[i] = "0123456789ABCDEF"[nbr % 16];
			nbr /= 16;
			i--;
		}
	}
	// printf("buff is : %s\n", buff);
	max = ft_max(ft_max(format->width, precision), len);
	// printf("max is : %d\n", max);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		else 
			memset(buff + (100 - 1 - len), '-', sizeof(char));
	}
	if (negative && max == len)
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
	{
		ft_putstr(&buff[100 - max]);
	}
}

void print_val_ss(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	const char *str;
	int i;
	int max;
	int len;
	int negative;
	int flag_prec;

	negative = 0;
	flag_prec = 0;
	buff[99] = '\0';
	i = 99;
	str = va_arg(a_list, const char *);
	if (str == NULL)
		ft_putstr("(null)");
	len = ft_strlen(str);
	if (format->precision == -1)
		precision = 0;
	else
	{
		flag_prec = 1;
		precision = format->precision;
	}
	memset(buff, ' ', 100 * sizeof(char));
	// memset(buff + (100 - precision), '0', precision * sizeof(char));
	// if (!format->width)
	// 	max = len;
	// else
	max = ft_max(format->width, len);
	// printf("width is : %d\n", format->width);
	// printf("precision is : %d\n", precision);
	// printf("len is : %d\n", len);
	if (flag_prec && !precision)
	{
		if (!format->width)
			ft_putstr("");
		else
			ft_putstr(&buff[100 - format->width]);
	}
	else
	{
		if (precision > 0 && precision < len)
		{
			max = ft_max(format->width, precision);
			len = precision;
		}
		len--;
		while (len >= 0)
		{
			buff[i] = str[len];
			// printf("str is : %c\n", str[len]);
			len--;
			i--;
		}
		ft_putstr(&buff[100 - max]);
	}
	// printf("max is : %d\n", max);
	// printf("max is : %d\n", max);
	// if(negative)
	// {
	// 	if(precision == max && precision > len) 
	// 	{
	// 		memset(buff + (100  - 2 - max), '-', sizeof(char));
	// 		ft_putchar(buff[100 - 2 - max]);
	// 	}
	// 	else if(precision > len)
	// 		memset(buff + (100 - 1 - precision), '-', sizeof(char));
	// 	else 
	// 		memset(buff + (100 - 1 - len), '-', sizeof(char));
	// }
	// if (negative && max == len)
	// {
	// 	ft_putstr(&buff[100 - 1 - max]);
	// }
	// else
	// {
	// }
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
	format->width_digit = i;
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
	else if (str[i] == 'u')
		format->specifier = 2;
	else if (str[i] == 'o')
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
			print_val_di(format, a_list);
		else if (format->specifier == 2)
			print_val_u(format, a_list);
		else if (format->specifier == 3)
			print_val_o(format, a_list);
		else if (format->specifier == 4)
			print_val_sx(format, a_list);
		else if (format->specifier == 5)
			print_val_X(format, a_list);
		else if (format->specifier == 14)
			print_val_ss(format, a_list);
	}
	if (format->length == 1)
	{
		if (format->specifier == 1)
			print_val_hdi(format, a_list);
		else if (format->specifier == 2)
			print_val_hu(format, a_list);
		// else if (format->specifier == 3)
		// 	print_val_o(format, a_list);
		// else if (format->specifier == 4)
		// 	print_val_sx(format, a_list);
		// else if (format->specifier == 5)
		// 	print_val_X(format, a_list);
		// else if (format->specifier == 16)
		// {
		// 	// print_val_n(&format, a_list);
		// }
	}
	if (format->length == 2)
	{
		if (format->specifier == 1)
			print_val_hhdi(format, a_list);
		else if (format->specifier == 2)
			print_val_hhu(format, a_list);
		// else if (format->specifier == 3)
		// 	print_val_o(format, a_list);
		// else if (format->specifier == 4)
		// 	print_val_sx(format, a_list);
		// else if (format->specifier == 5)
		// 	print_val_X(format, a_list);
		// else if (format->specifier == 16)
		// {
		// 	// print_val_n(&format, a_list);
		// }
	}
	if (format->length == 3)
	{
		if (format->specifier == 1)
			print_val_ldi(format, a_list);
		// else if (format->specifier == 2)
		// 	print_val_lu(format, a_list);
		// else if (format->specifier == 3)
		// 	print_val_o(format, a_list);
		// else if (format->specifier == 4)
		// 	print_val_sx(format, a_list);
		// else if (format->specifier == 5)
		// 	print_val_X(format, a_list);
		// else if (format->specifier == 16)
		// {
		// 	// print_val_n(&format, a_list);
		// }
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
	ft_printf("--------------------%%s--------------------\n");
	
	printf("21) Vrai PRINTF : |%s|\n", NULL);
	ft_printf("21) Mon PRINTF  : |%s|\n", NULL);
	// printf("22) Vrai PRINTF : |%10s|\n", NULL);
	// ft_printf("22) Mon PRINTF  : |%10s|\n", NULL);
	// printf("24) Vrai PRINTF : |%.2s|\n", NULL);
	// ft_printf("24) Mon PRINTF  : |%.2s|\n", NULL);
	// printf("25) Vrai PRINTF : |%10.8s|\n", NULL);
	// ft_printf("25) Mon PRINTF  : |%10.8s|\n", NULL);
	// printf("26) Vrai PRINTF : |%10.2s|\n", NULL);
	// ft_printf("26) Mon PRINTF  : |%10.2s|\n", NULL);
	// printf("27) Vrai PRINTF : |%2.10s|\n", NULL);
	// ft_printf("27) Mon PRINTF  : |%2.10s|\n", NULL);
	// printf("28) Vrai PRINTF : |%2.5s|\n", NULL);
	// ft_printf("28) Mon PRINTF  : |%2.5s|\n", NULL);
	// printf("30) Vrai PRINTF : |%1.0s|\n", NULL);
	// ft_printf("30) Mon PRINTF  : |%1.0s|\n", NULL);

	return 0;
}
