/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:15 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 15:07:19 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_write(char *my_var)
{
	errno = 0;
	if (!special_putendl(my_var, STDOUT_FILENO))
	{
		perror("env: write error");
		if (errno == ENOSPC)
			g_exit_status = 125;
		else
			g_exit_status = 1;
		return (0);
	}
	return (1);
}

void	ft_env(char **complete_cmd, char **my_envp)
{
	int	i;

	i = 0;
	if (complete_cmd[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", STDERR_FILENO);
		g_exit_status = 1;
		return ;
	}
	if (my_envp)
	{
		while (my_envp[i])
		{
			if (!check_write(my_envp[i]))
				return ;
			i++;
		}
	}
	g_exit_status = 0;
}
