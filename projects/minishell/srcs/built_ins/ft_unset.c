/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:42:35 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/07 14:42:37 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_env(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	remove_env(t_data *data, char *var)
{
	int		i;
	int		size;

	size = count_elements((void **)data->my_envp);
	i = 0;
	if (data->my_envp)
	{
		while (data->my_envp[i])
		{
			if (!ft_strnstr(data->my_envp[i], var, ft_strlen(var)))
				i++;
			else
			{
				free(data->my_envp[i]);
				data->my_envp[i] = data->my_envp[size - 1];
				data->my_envp[size - 1] = NULL;
				return ;
			}
		}
	}
}

void	ft_unset(char **cmd, t_data *data)
{
	int	i;

	if(!cmd[1])
		return ;
	i = 1;
	while (cmd[i])
	{
		if (!check_env(cmd[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_status = 1;
			i++;
			continue;
		}
		remove_env(data, cmd[i]);
		i++;
	}
	g_exit_status = 0;
}
