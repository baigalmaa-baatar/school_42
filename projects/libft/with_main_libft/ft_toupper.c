#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return(c - 32);
	}
	return (c);
}

int main()
{
	int c1;
	int c2;

	c1 = 125;
	c2 = 125;
	printf("My  function : %d\nStd function : %d\n", ft_toupper(c1), toupper(c2));
	return (0);
}