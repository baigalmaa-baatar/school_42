/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:02 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 15:07:06 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(char **my_envp)
{
	char	*pathname;
	char	*env_pwd;

	pathname = getcwd(NULL, 0);
	if (!pathname)
	{
		env_pwd = my_getenv("PWD", my_envp);
		if (!env_pwd)
		{
			ft_putstr_fd("minishell: pwd: Information not available\n",
				STDERR_FILENO);
			g_exit_status = 1;
			return ;
		}
		pathname = ft_strdup(env_pwd);
	}
	if (!special_putendl(pathname, STDOUT_FILENO))
	{
		perror("minishell: pwd: write error");
		g_exit_status = 1;
		free(pathname);
		return ;
	}
	free(pathname);
	g_exit_status = 0;
}
