#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return(c + 32);
	}
	return (c);
}

int main()
{
	int c1;
	int c2;

	c1 = 125;
	c2 = 125;
	printf("My  function : %d\nStd function : %d\n", ft_tolower(c1), tolower(c2));
	return (0);
}