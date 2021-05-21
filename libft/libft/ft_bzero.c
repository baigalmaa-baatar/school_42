#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}