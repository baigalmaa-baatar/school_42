#include "../inc/minishell.h"

void	ft_pwd(void)
{
	char	*pathname;

	pathname = getcwd(NULL, 0);
	if (!pathname)
		error_fct("minishell: Getcwd failure", 8); //can be changed to a better error msg
	printf("%s\n", pathname);
	free(pathname);
	exit_status = 0;
}