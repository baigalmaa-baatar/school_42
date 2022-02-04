#include "../inc/minishell.h"

char	**find_path(char **my_envp)
{
	char	*path_env;
	char	**path;

	path_env = my_getenv("PATH", my_envp);
	if (!path_env)
		return (NULL);
	path = ft_split(path_env, ':');
	if (!path)
	{
		perror("minishell: Malloc failure");
		ft_free_tab(my_envp);
		exit(2);
	}
	return (path);
}
