#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

int main()
{
    char str[50] = "aa";
    // char str1[50] = "aa";

	ft_bzero(str, 1*sizeof(char));
	// bzero(str1, 1*sizeof(char));
	printf("My  function : %s\nStd function : %s\n", str, str);
	return (0);
}