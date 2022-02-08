/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:56:55 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/07 19:56:58 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*test_cmd_path(char **path, char *cmd, int *slash)
{
	int		i;
	char	*cmd_path;

	i = 0;
	if (ft_strchr(cmd, '/'))
		*slash = 1;
	if (path)
	{
		while (path[i])
		{
			cmd_path = ft_mtp_strjoin(path[i], "/", cmd);
			if (access(cmd_path, X_OK) == -1)
			{
				free (cmd_path);
				i++;
			}
			else
				return (cmd_path);
		}
	}
	if (access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	return (NULL);
}

int	check_if_dir(char *s)
{
	struct stat	buf;

	if (!s || stat(s, &buf) == -1)
		return (-1);
	return (S_ISDIR(buf.st_mode));
}

int	check_file(char **complete_cmd, char *tmp, int slash, int dir)
{
	if ((tmp && !slash && dir)
		|| (!tmp && !slash && dir == -1))
	{
		ft_mtp_putendl_fd(STDERR_FILENO, "minishell: ", complete_cmd[0], NF);
		free(tmp);
		g_exit_status = 127;
		return (0);
	}
	if (tmp && slash && dir)
	{
		ft_mtp_putendl_fd(STDERR_FILENO, "minishell: ", complete_cmd[0], ISD);
		free(tmp);
		g_exit_status = 126;
		return (0);
	}
	if (!tmp && slash && dir == -1)
	{
		ft_mtp_putendl_fd(STDERR_FILENO, "minishell: ", complete_cmd[0], NSFD);
		g_exit_status = 127;
		return (0);
	}
	return (1);
}

char	**find_cmds(char **complete_cmd, t_data *data)
{
	int		dir;
	int		slash;
	char	*tmp;

	slash = 0;
	ft_free_tab(data->path);
	data->path = find_path(data->my_envp);
//	printf("dir = %d\n", check_if_dir(complete_cmd[0]));
	tmp = test_cmd_path(data->path, complete_cmd[0], &slash);
	dir = check_if_dir(tmp);
	if (!check_file(complete_cmd, tmp, slash, dir))
	{
		ft_free_tab(complete_cmd);
		return (NULL);
	}
//	printf("dir = %d\n", check_if_dir(tmp));
//	printf("tmp = %s\n", tmp);
	free(complete_cmd[0]);
	complete_cmd[0] = tmp;
	return (complete_cmd);
}
