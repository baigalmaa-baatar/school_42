#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if ((*s1 != *s2 && s1 && s2) || (*s1 == '\0' || *s2 == '\0'))
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int main()
{
	// char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	// char *s2 = "\x12\x02";
	// size_t size = 6;
	// int i1 = ((strncmp(s1, s2, size) > 0) ? 1 : ((strncmp(s1, s2, size) < 0) ? -1 : 0));
	// int i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
	// printf("My  function : %d\nStd function : %d\n", i2, i1);

	// char buff1[] = "a";
	// char buff2[] = "a2cdefghijklmnopqrstuvwxyz";

	// char buff3[] = "a";
	// char buff4[] = "a2cdefghijklmnopqrstuvwxyz";

	// printf("My  function : %d\nStd function : %d\n", ft_strncmp(buff1, buff2, 26 * sizeof(char)), strncmp(buff3, buff4, 26 * sizeof(char)));

	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	char *s2 = "\x12\x02";
	size_t size = 6;
	int i1 = ((strncmp(s1, s2, size) > 0) ? 1 : ((strncmp(s1, s2, size) < 0) ? -1 : 0));
	int i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
	printf("My  function : %u\nStd function : %u\n", i2, i1);
}
