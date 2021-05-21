#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t result;

	if (!dstsize)
		return (ft_strlen(src));
	result = dstsize + ft_strlen(src);
	if (!ft_strlen(dst))
		result = ft_strlen(src);
	i = 0;
	j = ft_strlen(dst);
	while (j < (dstsize - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (j < dstsize)
		dst[j] = '\0';
	return (result);
}

int main()
{
	char dst1[4] = "";
	char dst2[4] = "";
	size_t r1 = 	strlcat(dst1, "thx to ntoniolo for this test !", 4);
	size_t r2 = ft_strlcat(dst2, "thx to ntoniolo for this test !", 4);

	printf("Std function : %zu\n My function : %zu\n", r1, r2);

	printf("Std function : %s\n My function : %s\n", dst1, dst2);
	printf("Length of src %zu\n", strlen("thx to ntoniolo for this test !"));
	// printf("Length of dst %zu\n", strlen(dst1));
	// printf("Length of max %zu\n", max);
	// printf("Length of dst + src %zu\n", strlen(dst1) + strlen(src));

	// char str_dst[50] = "abc";
	// char str1_dst[50] = "abc";
	// char str_src[50] = "xyz";
	// char str1_src[50] = "xyz";

	// printf("My  function : %lu\nStd function : %lu\n", ft_strlcat(str_dst, str_src, 7 * sizeof(char)), strlcat(str1_dst, str1_src, 7 * sizeof(char)));
	// printf("My  function : %s\nStd function : %s\n", str_dst, str1_dst);
	return (0);
}