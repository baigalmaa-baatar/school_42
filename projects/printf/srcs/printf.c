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

char	*ft_strdup(const char *str)
{
	char			*res;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen (str);
	res = (char *)malloc (sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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
	max = ft_max(ft_max(format->width, precision), len);
	if(negative)
	{
		if(precision == max && precision > len) 
		{
			memset(buff + (100  - 2 - max), '-', sizeof(char));
			ft_putchar(buff[100 - 2 - max]);
		}
		else if(precision > len)
		{	
			memset(buff + (100 - 1 - precision), '-', sizeof(char));
		}
		else
		{
			memset(buff + (100 - 1 - len), '-', sizeof(char));
		}
	}
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
	{
		ft_putstr(&buff[100 - 1 - max]);
	}
	else
	{
		ft_putstr(&buff[100 - max]);
	}
}

void print_val_s(struct s_format *format, va_list a_list)
{
	int precision;
	char buff[100];
	const char *str;
	int i;
	int max;
	int len;
	int flag_prec;

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
	max = ft_max(format->width, len);
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
			len--;
			i--;
		}
		ft_putstr(&buff[100 - max]);
	}
}

int print_val_c(struct s_format *format, va_list a_list)
{
	char buff[100];
	char c;
	int num_chars;

	num_chars = 0;
	buff[99] = '\0';
	memset(buff, ' ', 100 * sizeof(char));
	c = (char) va_arg(a_list, int);
	if(!c)
	{
		ft_putstr("");
		return(0);
	}
	buff[99] = c;
	num_chars = ft_max(format->width, 1);
	ft_putstr(&buff[100 - num_chars]);
	// printf("num chars : %d\n", num_chars);
	return (num_chars);
}

void print_val_p(struct s_format *format, va_list a_list)
{
	char buff[100];
	int max;
	int i;
	unsigned long long nbr;

	i = 99;
	buff[i] = '\0';
	memset(buff, ' ', 100 * sizeof(char));
	nbr = va_arg(a_list, unsigned long long);
	if (!nbr)
	{	
		ft_putstr(&buff[100 - format->width + 3]);
		ft_putstr("0x0");
	}
	else
	{
		while(nbr > 0)
		{
			buff[i] = "0123456789abcdef"[nbr % 16];
			nbr /= 16;
			i--;
		}
		buff[i] = 'x';
		buff[i - 1] = '0';
		max = ft_max(format->width, 99 - i + 2);
		ft_putstr(&buff[100 - max]);
	}
}

void print_val_perc(void)
{
	write(1, "%", 1);
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

int print_val(char *str, struct s_format *format, va_list a_list)
{
	int num_char;

	num_char = 0;
	if (str[0] == 'c')
		num_char = print_val_c(format, a_list);
	else if (str[0] == 's')
		print_val_s(format, a_list);
	else if (str[0] == 'p')
		print_val_p(format, a_list);
	else if (str[0] == 'd' || str[0] == 'i')
		print_val_di(format, a_list);
	else if (str[0] == 'u')
		print_val_u(format, a_list);
	else if (str[0] == 'x')
		print_val_sx(format, a_list);
	else if (str[0] == 'X')
		print_val_X(format, a_list);
	else if (str[0] == '%')
		print_val_perc();
	else
		return (0);
	return (num_char);
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
	// printf("%d\n", printf("|%c|", 'a'));
	// printf("%d\n", printf("|%c|", 'a'));
	// ft_printf("%d\n", ft_printf("%c\n", 'a'));

	// printf("%d\n", printf("%c", 'a'));
	// ft_printf("%d\n", ft_printf("%c", 'a'));
	// printf(" %c ", '0');
	// ft_printf(" %c ", '0');

	// printf("%d\n", printf("kkk"));
	// ft_printf("%d\n", ft_printf("kkk"));

	printf("%d\n", printf("%c%c%c", 'a', 'b', 'c'));
	ft_printf("%d\n", ft_printf("%c%c%c", 'a', 'b', 'c'));

	// printf("%c ", '0' + 256);
	// ft_printf("%c ", '0' + 256);
	// printf(" %c %c %c ", '0', 0, '1');
	// ft_printf(" %c %c %c ", '0', 0, '1');
	// printf(" %c %c %c ", ' ', ' ', ' ');
	// ft_printf(" %c %c %c ", ' ', ' ', ' ');
	// printf(" %c %c %c ", '1', '2', '3');
	// ft_printf(" %c %c %c ", '1', '2', '3');
	// printf(" %c %c %c ", '2', '1', 0);
	// ft_printf(" %c %c %c ", '2', '1', 0);
	// printf(" %c %c %c ", 0, '1', '2');
	// ft_printf(" %c %c %c ", 0, '1', '2');

	return 0;
}