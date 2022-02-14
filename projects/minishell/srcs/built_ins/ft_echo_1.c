/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:58 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 15:08:00 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_cases(char **complete_cmd, int i, int newline, int save_index);

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
	int	save_index;

	if (complete_cmd[1])
	{		
		newline = option_n(complete_cmd, &i);
		save_index = i;
		while (complete_cmd[i])
		{
			if (check_cases(complete_cmd, i, newline, save_index) == -1)
				return ;
			i++;
		}
	}
	else
	{
		if (!special_putstr("\n", STDOUT_FILENO))
		{
			perror("minishell: echo: write error");
			g_exit_status = 1;
			return ;
		}
	}
	g_exit_status = 0;
}
