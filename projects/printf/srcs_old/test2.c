#include <stdio.h>
#include <string.h>
#include <unistd.h>
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

// int main(void)
// {
// 	format->width = 10;
// 	format->precision = 5;

// 	print_val_wp(&format, a_list);
// 	return (0);
// }