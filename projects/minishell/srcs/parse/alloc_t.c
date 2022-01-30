#include "../../inc/minishell.h"

char	**alloc_t(void)
{
	int i;
	char **arr;

	arr = (char **)malloc(100 * sizeof(char *));
	memset (arr, 0, 100 * sizeof(char *));
	i = 0;
	while (i < 100)
	{
		arr[i] = (char *)malloc(100 * sizeof(char));
		memset (arr[i], 0, 100 * sizeof(char));
		i++;
	}
	return (arr);
}