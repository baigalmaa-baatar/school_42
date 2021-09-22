#include <libc.h>
#include "include/ft_printf.h"
#include <limits.h>

int main()
{
	printf("The REAL PRINTF says : %d\n", printf(" hello |%20.12u| |%20.12d| |%20.12i| |%20.12x|\n", -25, -25, -25, -25));
	printf("YOUR ARTISINAL PRINTF says : %d\n", ft_printf(" hello |%20.12u| |%20.12d| |%20.12i| |%20.12x|\n", -25, -25, -25, -25));
}
