#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char *ptr_s;
	size_t len;
	size_t i;

	ptr_s = (char *)s;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (i <= len)
	{
		if (ptr_s[i] == (const char)c)
		{
			return (&ptr_s[i]);
		}
		i++;
	}
	return (NULL);
}