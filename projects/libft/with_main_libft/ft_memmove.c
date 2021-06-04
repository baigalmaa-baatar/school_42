#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;

	if (!ptr_dst && !ptr_src)
		return (NULL);
	
	if (ptr_dst < ptr_src)
	{
		while(len)
		{
			*ptr_dst = *ptr_src;
			ptr_dst++;
			ptr_src++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
	}
	return(dst);
}

	// if (dst > src)
	// {
	// 	while (len > 0)
	// 	{
	// 		((char *)dst)[len - 1] = ((char *)src)[len - 1];
	// 		len--;
	// 	}
	// }
	// else
	// {
	// 	i = 0;
	// 	while (i < len)
	// 	{
	// 		((char *)dst)[i] = ((char *)src)[i];
	// 		i++;
	// 	}
	// }
	// return (dst);

int main()
{
	// char str_dst[50] = "Geeks is for programming geeks.";
	// char str1_dst[50] = "Geeks is for programming geeks.";
	// char str_src[50] = "aab";
	// char str1_src[50] = "aab";
	// unsigned char c = 'b';

	// printf("My  function : %s\nStd function : %s\n", ft_memccpy(str_dst, str_src, c, 4*sizeof(char)), memccpy(str1_dst, str1_src, c, 4*sizeof(char)));
	// return (0);

	char buff1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char buff2[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *src1 = "thiß ";
	char *src2 = "thiß ";

	printf("My  function : %s\nStd function : %s\n", ft_memmove(buff1 +3, src1, 10*sizeof(char)), memmove(buff2+3, src2, 10*sizeof(char)));
	return (0);
}