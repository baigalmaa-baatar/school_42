#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *ptr_s1;
	unsigned char *ptr_s2;
	size_t i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;

	i = 0;
	while (i < len)
	{
		if (ptr_s1[i] != ptr_s2[i])
		{
			return (ptr_s1[i] - ptr_s2[i]);
		}
		i++;
	}
	return (0);
}

int main()
{
	char buff1[] = "a1bcdefghijklmnopqrstuvwxyz";
	char buff2[] = "a2cdefghijklmnopqrstuvwxyz";

	char buff3[] = "a1cdefghijklmnopqrstuvwxyz";
	char buff4[] = "a2cdefghijklmnopqrstuvwxyz";

	printf("My  function : %d\nStd function : %d\n", ft_memcmp(buff1, buff2, 26 * sizeof(char)), memcmp(buff3, buff4, 26 * sizeof(char)));
	return (0);


	// char *src1 = "/|\x12\xff\x09\x42\042\42|\\";
	// char *src2 = "/|\x12\xff\x09\x42\042\42|\\";
	// printf("My  function : %s\nStd function : %s\n", ft_memchr(src1, '\x42', 10 * sizeof(char)), memchr(src2, '\x42', 10 * sizeof(char)));
	// return(0);
}