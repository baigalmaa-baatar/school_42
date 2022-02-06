/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:08:09 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 15:08:11 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_args(char **complete_cmd)
{
	if (complete_cmd[2])
	{	
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		g_exit_status = 1;
		return (-1);
	}
	if (chdir(complete_cmd[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(complete_cmd[1]);
		g_exit_status = 1;
		return (-1);
	}
	return (0);
}

void	ft_cd(char **complete_cmd, t_data *data)
{
	char	*pwd;

	if (complete_cmd[1])
	{
		if (check_args(complete_cmd) == -1)
			return ;
	}
	else
	{
		ft_putstr_fd("minishell: cd: No directory\n", STDERR_FILENO);
		g_exit_status = 1;
		return ;
	}
	change_env_value(data, "OLDPWD", my_getenv("PWD", data->my_envp));
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		change_env_value(data, "PWD", pwd);
		free(pwd);
	}
	g_exit_status = 0;
}
