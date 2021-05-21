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