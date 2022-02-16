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

int	check_empty(char *param)
{
	if (!param || !ft_strcmp(param, ""))
		return (1);
	else
		return (0);
}

void	export_set_env(char *cmd, t_data *data)
{
	int	pos;

	pos = check_env_ex(cmd);
	if (!pos)
	{
		print_err(cmd);
		g_exit_status = 1;
		return ;
	}
	if (pos > 0)
		add_env(cmd, data, pos);
}

void	ft_export(char **cmd, t_data *data)
{
	int	i;
	int	non_empty_args;

	g_exit_status = 0;
	non_empty_args = 0;
	i = 1;
	while (cmd[i])
	{
		if (check_empty(cmd[i]))
		{
			i++;
			continue ;
		}
		non_empty_args++;
		export_set_env(cmd[i], data);
		i++;
	}
	if (!non_empty_args)
		sort_print(data);
}
