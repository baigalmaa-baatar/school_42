#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

int main()
{
	int width = 0;
	int precision = 1;
	char temp_p[precision];
	char buff[100];
	int nbr;
	int i;
	int max;
	int len;

	memset(buff, ' ', 100 * sizeof(char));
	memset(buff + (100 - 1 - precision), '0', precision * sizeof(char));
	buff[99] = 0;
	i = 98;
	nbr = 123;
	len = ft_length_nbr(nbr);
	while(nbr > 0)
	{
		buff[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	max = ft_max(ft_max(width, sizeof(temp_p)), len);
	printf("standard output : |%.1d|\n", 123);
	ft_putstr(&buff[100 - 1 - max]);
	write(1, "\n", 1);
	return 0;
}