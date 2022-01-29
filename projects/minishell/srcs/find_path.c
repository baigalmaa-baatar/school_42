#include "../inc/minishell.h"

char	**find_path(void)
{
	char	*path_env;
	char	**path;

	path_env = getenv("PATH");  //if we use "my_envp" variable, we'll have to change this.
	if (!path_env)				// Instead of using getenv we'll have to search PATH in my_envp
	{
		ft_putstr_fd("minishell: PATH not found\n", STDERR_FILENO);
		exit(1);
	}
	path = ft_split(path_env, ':');
	if (!path)
	{
		perror("minishell: Malloc failure");
		exit(3);
	}
	return (path);
}
