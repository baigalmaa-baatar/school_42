#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	while (0 != len && s[len] != (const char)c)
	{
		len--;
	}
	if (s[len] == (const char)c)
	{
		return ((char *)&s[len]);
	}
	return (NULL);
}