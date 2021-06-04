#include "libft.h"

void *ft_memchr(const void *str, int c, size_t len)
{
	unsigned char *ptr_str;
	size_t i;

	ptr_str = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		if (ptr_str[i] == (unsigned char)c)
		{
			return (&ptr_str[i]);
		}
		i++;
	}
	return (NULL);
}

int main()
{
	// char buff1[] = "abcdefghijklmnopqrstuvwxyz";
	// char buff2[] = "abcdefghijklmnopqrstuvwxyz";
	// unsigned char needle1 = 'd';
	// unsigned char needle2 = 'd';

	// printf("My  function : %s\nStd function : %s\n", ft_memchr(buff1, needle1, 1 * sizeof(char)), memchr(buff2, needle2, 1 * sizeof(char)));
	// return (0);


	char *src1 = "/|\x12\xff\x09\x42\042\42|\\";
	char *src2 = "/|\x12\xff\x09\x42\042\42|\\";
	// int size = 10;

	// if (memchr(src, '\x42', size) == ft_memchr(src, '\x42', size))
	printf("My  function : %s\nStd function : %s\n", ft_memchr(src1, '\x42', 10 * sizeof(char)), memchr(src2, '\x42', 10 * sizeof(char)));
	return(0);
}