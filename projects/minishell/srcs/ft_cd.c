#include "../inc/minishell.h"

void	change_value(t_data *data, char *var, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->my_envp)
	{
		while (data->my_envp[i])
		{
			if (!ft_strnstr(data->my_envp[i], var, ft_strlen(var)))
				i++;
			else
			{
				tmp = ft_mtp_strjoin(var, "=", new_value);
				free(data->my_envp[i]);
				data->my_envp[i] = tmp;
				return ;
			}
		}
	}
}

void	ft_cd(char **complete_cmd, t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	/*if (!pwd)
	{
		ft_putstr_fd("minishell: getcwd: Information not available",
			STDERR_FILENO);
		g_exit_status = 1;
		return ;
	}*/
	if (complete_cmd[1])
	{
		if (complete_cmd[2])
		{	
			ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
			g_exit_status = 1;
			free(pwd);
			return ;
		}
		if (chdir(complete_cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			perror(complete_cmd[1]);
			g_exit_status = 1;
			free(pwd);
			return ;
		}
	}
	else
	{
		ft_putstr_fd("minishell: cd: No directory\n", STDERR_FILENO);
		g_exit_status = 1;
		free(pwd);
		return ;
	}
	change_value(data, "OLDPWD", pwd);
	free(pwd);
	pwd = getcwd(NULL, 0);
	change_value(data, "PWD", pwd);
	free(pwd);
	g_exit_status = 0;
}
