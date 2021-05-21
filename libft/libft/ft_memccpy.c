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