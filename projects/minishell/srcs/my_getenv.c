#include "../inc/minishell.h"

char	*my_getenv(char *name, char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strnstr(envp[i], name, ft_strlen(name))
			&& envp[i][ft_strlen(name)] == '=')
			return (&(envp[i][ft_strlen(name) + 1]));
		else
			i++;
	}
	return (NULL);
}
