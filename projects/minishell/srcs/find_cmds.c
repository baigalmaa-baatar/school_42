#include "../inc/minishell.h"

char	*test_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (path)
	{
		while (path[i])
		{
			cmd_path = ft_mtp_strjoin(path[i], "/", cmd);
			if (access(cmd_path, F_OK) == -1)
			{
				free (cmd_path);
				i++;
			}
			else
				return (cmd_path);
		}
	}
	if (access(cmd, F_OK) != -1)
		return (ft_strdup(cmd));
	return (NULL);
}

char	**find_cmds(char **complete_cmd, t_data *data)
{
	char	*tmp;

	/*****Update of path*****/
	/*	I'll comment out this part for now.
		We'll test it later with unset & export 

	ft_free_tab(data->path);					
	data->path = find_path(data->my_envp);
	
	*/
	tmp = test_cmd_path(data->path, complete_cmd[0]);
	if (!tmp)
	{
		ft_mtp_putendl_fd(STDERR_FILENO, "minishell: ", complete_cmd[0], NF);
		ft_free_tab(complete_cmd);
		g_exit_status = 127;
		return (NULL);
	}
	free(complete_cmd[0]);
	complete_cmd[0] = tmp;
	return (complete_cmd);
}
