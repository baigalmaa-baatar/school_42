#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)b;
	while (len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return(b);
}

int main()
{
    char str[50] = "Geeks is for programming geeks.";
	char str1[50] = "Geeks is for programming geeks.";
	printf("My  function : %s\nStd function : %s\n", ft_memset(str, '.', 10*sizeof(char)), memset(str1, '.', 10*sizeof(char)));
	return (0);
}