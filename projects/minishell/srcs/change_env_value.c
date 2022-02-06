/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:52:18 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/06 13:52:21 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	change_env_value(t_data *data, char *var, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->my_envp)
	{
		while (data->my_envp[i])
		{
			if (!ft_strnstr(data->my_envp[i], var, ft_strlen(var)))
				i++;
			else
			{
				tmp = ft_mtp_strjoin(var, "=", new_value);
				if (!tmp)
					error_fct(data, "minishell: Malloc failure", 2);
				free(data->my_envp[i]);
				data->my_envp[i] = tmp;
				return ;
			}
		}
	}
}
