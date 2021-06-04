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

int main()
{
	// char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";

	char *src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";

	printf("My  function : %s\nStd function : %s\n", ft_strrchr(src, L'–'), strrchr(src, L'–'));

	// char *src1 = "/|\x12\xff\x09\x42\042\42|\\";
	// char *src2 = "/|\x12\xff\x09\x42\042\42|\\";

	// printf("My  function : %s\nStd function : %s\n", ft_strchr(src1, '\x42'), strchr(src2, '\x42'));
	return (0);
}