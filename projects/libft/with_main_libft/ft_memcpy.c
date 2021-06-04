#include "libft.h"

char	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;

	if (!n || ptr_dst == ptr_src)
		return (dst);

	while (n)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return(dst);
}

int main()
{
    // char str_dst[50] = "Geeks is for programming geeks.";
	// char str1_dst[50] = "Geeks is for programming geeks.";
	// char str_src[50] = "Nana";
	// char str1_src[50] = "Nana";

	// printf("My  function : %s\nStd function : %s\n", ft_memcpy(str_dst, str_src, 4*sizeof(char)), memcpy(str1_dst, str_src, 4*sizeof(char)));
	// return (0);

	char str_dst[50] = "Geeks is for programming geeks.";
	char str1_dst[50] = "Geeks is for programming geeks.";
	// str_dst = malloc(sizeof *str_dst);
	// str1_dst = malloc(sizeof *str1_dst);

	char str_src[50] = "aaa";
	char str1_src[50] = "aaa";
	// str_src = malloc(sizeof *str_src);
	// str1_src = malloc(sizeof *str1_src);

	printf("My  function : %s\nStd function : %s\n", ft_memcpy(str_dst, str_src, 3*sizeof(char)), memcpy(str1_dst, str1_src, 3*sizeof(char)));
	// printf("Std function : %s\n", memcpy(str1_dst, str1_src, 3*sizeof(char)));

	return (0);
}