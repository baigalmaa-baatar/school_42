/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:58 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 15:08:00 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_strfind(char c, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	option_n(char **complete_cmd, int *index)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (complete_cmd[i])
	{
		*index = i;
		if (ft_strnstr(complete_cmd[i], "-n", 2))
		{
			newline = 0;
			if (!ft_strfind('n', &complete_cmd[i][1]))
			{
				if (i == 1)
					newline = 1;
				return (newline);
			}
		}
		else
			return (newline);
		i++;
	}
	return (newline);
}

void	ft_echo(char **complete_cmd)
{
	int	i;
	int	newline;

	if (complete_cmd[1])
	{		
		newline = option_n(complete_cmd, &i);
		while (complete_cmd[i])
		{
			if (newline && !complete_cmd[i + 1])
				ft_putendl_fd(complete_cmd[i], STDOUT_FILENO);
			else if (!newline && !complete_cmd[i + 1])
				ft_putstr_fd(complete_cmd[i], STDOUT_FILENO);
			else
				ft_mtp_putstr_fd(complete_cmd[i], " ", NULL, STDOUT_FILENO);
			i++;
		}
	}
	g_exit_status = 0;
}
