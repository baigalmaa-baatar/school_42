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

int main()
{
	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";

	printf("My  function : %s\nStd function : %s\n", ft_strchr(src, '\0'), strchr(src, '\0'));

	// char *src1 = "/|\x12\xff\x09\x42\042\42|\\";
	// char *src2 = "/|\x12\xff\x09\x42\042\42|\\";

	// printf("My  function : %s\nStd function : %s\n", ft_strchr(src1, '\x42'), strchr(src2, '\x42'));
	return (0);
}