/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:02:39 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 21:24:40 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	print_err(char *cmd)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	ft_export(char **cmd, t_data *data)
{
	int	i;
	int	pos;

	g_exit_status = 0;
	if (!cmd[1])
	{
		sort_print(data);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		pos = check_env_ex(cmd[i]);
		if (!pos)
		{
			print_err(cmd[i]);
			g_exit_status = 1;
			i++;
			continue ;
		}
		if (pos > 0)
			add_env(cmd[i], data, pos);
		i++;
	}
}
