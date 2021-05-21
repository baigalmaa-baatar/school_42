#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;
	size_t i;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (!n || ptr_dst == ptr_src)
		return (0);
	i = 0;
	while (n > i || ptr_src[i] != '\0')
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
		{
			return(&ptr_dst[i + 1]);
		}
		i++;
	}
	return(0);
}

int main()
{
	// char str_dst[50] = "Geeks is for programming geeks.";
	// char str1_dst[50] = "Geeks is for programming geeks.";
	// char str_src[50] = "aab";
	// char str1_src[50] = "aab";
	// unsigned char c = 'b';

	// printf("My  function : %s\nStd function : %s\n", ft_memccpy(str_dst, str_src, c, 4*sizeof(char)), memccpy(str1_dst, str1_src, c, 4*sizeof(char)));
	// return (0);

	char buff1[] = "abcdefghijklmnopqrstuvwxyz";
	char buff2[] = "abcdefghijklmnopqrstuvwxyz";
	char *src1 = "string with\200inside !";
	char *src2 = "string with\200inside !";

	unsigned char c = '\200';

	printf("My  function : %s\nStd function : %s\n", ft_memccpy(buff1, src1, c, 21*sizeof(char)), memccpy(buff2, src2, c, 21*sizeof(char)));
	return (0);

}