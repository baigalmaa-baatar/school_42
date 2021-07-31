#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
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
    int digit = 10;
    char temp[digit];
    int x = 123;

    memset(temp, '0', sizeof(temp));
    temp[digit] = 0;
    
    int i = digit - 1;
    while (x > 0) {
        temp[i--] = x % 10 + '0';
        x /= 10;
    }
    ft_putstr(temp);
    return 0;
}

// int main()
// {
//     int digit = 10;
//     // char temp[digit];
//     char temp1[digit];
//     int len;
//     int i;
//     char str[] = "abc";

//     // memset(temp, '0', sizeof(temp));
//     temp1[digit] = 0;
    
//     i = digit - 1;
//     len = strlen   (str);
//     len--;
//     while (len > -1) {
//         temp1[i--] = str[len];
//         len--;
//     }
//     ft_putstr(temp1);
//     printf("\n");
//     // printf("%.3s", "abcde");
//     return 0;
// }