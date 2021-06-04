#include "libft.h"

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;

	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

int main()
{
	char str_dst[50] = "abc";
	char str1_dst[50] = "abc";
	char str_src[50] = "xyz";
	char str1_src[50] = "xyz";

	printf("My  function : %lu\nStd function : %lu\n", ft_strlcpy(str_dst, str_src, 1 * sizeof(char)), strlcpy(str1_dst, str1_src, 1 * sizeof(char)));
	printf("My  function : %s\nStd function : %s\n", str_dst, str1_dst);
	return (0);
}