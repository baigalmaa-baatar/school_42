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