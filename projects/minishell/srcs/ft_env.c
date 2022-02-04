#include "../inc/minishell.h"

void	ft_env(char **complete_cmd, char **envp)
{
	int	i;

	i = 0;
	if (complete_cmd[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", STDERR_FILENO);
		g_exit_status = 1;
		return ;
	}
	if (envp)
	{
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			i++;
		}
	}
	g_exit_status = 0;
}
