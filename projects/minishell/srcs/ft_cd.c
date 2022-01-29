#include "../inc/minishell.h"

void	ft_cd(char **complete_cmd)
{
	if (complete_cmd[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments ", STDERR_FILENO);
		exit_status = 1;
		return ;
	}
	if (chdir(complete_cmd[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(complete_cmd[1]);
		exit_status = 1;
		return ;
	}
	exit_status = 0;
}
