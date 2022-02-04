#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\t'
		|| c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}
