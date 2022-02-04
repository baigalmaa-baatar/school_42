#include "libft.h"

int	ft_nb_occurences(char c, char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
