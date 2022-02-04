#include "../inc/minishell.h"

void	ft_pwd(void)
{
	char	*pathname;

	pathname = getcwd(NULL, 0);
	if (!pathname)
	{
		ft_putstr_fd("minishell: pwd: Information not available\n",
			STDERR_FILENO);
		g_exit_status = 1;
		return ;
	}
	printf("%s\n", pathname);
	free(pathname);
	g_exit_status = 0;
}
