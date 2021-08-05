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

//[min width][precision][length modifier][conversion specifier]

#include "../include/ft_printf.h"

int ft_length_nbr(int nbr)
{
	int i = 0;
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

void print_val_wp(struct s_format *format, va_list a_list)
{
	char temp_p[format->precision];
	char buff[100];
	int nbr;
	int i;
	int max;
	int len;

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
	printf("standard output : |%.1d|\n", 123);
	ft_putstr(&buff[100 - 1 - max]);
	write(1, "\n", 1);
	return 0;
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
		// printf("here is the format->precision : %c\n", str[i]);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	format->width = nbr;
	format->width_digit = i;
	// printf("here is the format->precision_digit : %d\n", format->precision_digit);
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
		// printf("here is the format->precision : %c\n", str[i]);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	format->precision = nbr;
	format->precision_digit = i;
	// printf("here is the format->precision_digit : %d\n", format->precision_digit);
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
		format->specifier = 1;
	else if (str[i] == 'X')
		format->specifier = 1;
	else if (str[i] == 'D' || str[i] == 'O' || str[i] == 'U')
		format->specifier = 2;
	else if (str[i] == 'e' || str[i] == 'E')
		format->specifier = 3;
	else if (str[i] == 'f' || str[i] == 'F')
		format->specifier = 4;
	else if (str[i] == 'g' || str[i] == 'G')
		format->specifier = 5;
	else if (str[i] == 'a' || str[i] == 'A')
		format->specifier = 6;
	else if (str[i] == 'C')
		format->specifier = 7;
	else if (str[i] == 'c')
		format->specifier = 8;
	else if (str[i] == 'S')
		format->specifier = 9;
	else if (str[i] == 's')
		format->specifier = 10;
	else if (str[i] == 'p')
		format->specifier = 11;
	else if (str[i] == 'n')
		format->specifier = 12;
	else if (str[i] == '%')
		format->specifier = 13;
	else
		return (0);
	return (1);
}

void print_val(struct s_format *format, va_list a_list)
{

	if (format->specifier == 1)
	{
		if(format->length == 1)
		{
			if (format->precision != -1 && format->width > format->precision)
					{
						format->width -= format->precision;
    					char temp_w[format->width];
						memset(temp_w, ' ', sizeof(temp_w));
    					ft_putstr(temp_w);

						int curr_nbr = va_arg(a_list, int);
    					char temp[format->precision];

						memset(temp, '0', sizeof(temp));
    					temp[format->precision] = 0;
    					format->precision--;
				    	while (curr_nbr > 0)
						{
        					temp[format->precision--] = curr_nbr % 10 + '0';
        					curr_nbr /= 10;
    					}
    					ft_putstr(temp);
					}
			signed char sc = va_arg(a_list, int);
			ft_putnbr_char(sc);
		}
		else if(format->length == 2)
		{
			short sh = va_arg(a_list, int);
			ft_putnbr_short(sh);
		}
		else if(format->length == 0)
		{
			if (format->width != 0)
				{
					if (format->precision != -1 && format->width > format->precision)
					{
						format->width -= format->precision;
    					char temp_w[format->width];
						memset(temp_w, ' ', sizeof(temp_w));
    					ft_putstr(temp_w);

						int curr_nbr = va_arg(a_list, int);
    					char temp[format->precision];

						memset(temp, '0', sizeof(temp));
    					temp[format->precision] = 0;
    					format->precision--;
				    	while (curr_nbr > 0) 
						{
        					temp[format->precision--] = curr_nbr % 10 + '0';
        					curr_nbr /= 10;
    					}
    					ft_putstr(temp);
					}
					else
					{
						int curr_nbr = va_arg(a_list, int);
    					char temp[format->width];

						memset(temp, ' ', sizeof(temp));
    					temp[format->width] = 0;
    					format->width--;
				    	while (curr_nbr > 0) 
						{
        					temp[format->width--] = curr_nbr % 10 + '0';
        					curr_nbr /= 10;
    					}
    					ft_putstr(temp);
					}
				}
		}
	}
	if (format->specifier == 2)
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
			if (detect_width((char *)&input[i], &format) != 0)
			{
				i += format.width_digit;
			}
			if(input[i] == '.')
			{
				i++;
				detect_precision((char *)&input[i], &format);
				i += format.precision_digit;
			}
			if (detect_length((char *)&input[i], &format) != 0)
			{
				i++;
			}
			if (detect_specifier((char *)&input[i], &format) != 0)
			{
				// i++;
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
	// printf("07) Vrai PRINTF : |%.d|\n", 100);
	// ft_printf("07) Mon PRINTF  : |%.d|\n", 100);
	printf("Standard output : |%u|\n", -1);
	// ft_printf("   My function  : |%3d|\n", 100);

	return 0;
}