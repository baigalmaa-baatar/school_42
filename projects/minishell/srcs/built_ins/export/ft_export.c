/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:02:39 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/07 16:02:40 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	find_equal(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**alloc_envs(int size, char **envs)
{
	char	**new;
	int	i;

	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (envs[i] && i < size)
	{
		new[i] = ft_strdup(envs[i]);
		i++;
	}
	new[size] = 0;
	ft_free_tab(envs);
	return (new);
}

int	check_env_ex(char *s)
{
	int	pos;
	int ret;
	char *key = NULL;

	ret = 0;
	pos = find_equal(s);
	if (pos > 0)
	{
		key = ft_substr(s, 0, pos);
		if(check_env(key))
			ret = pos;
	}
	if (pos < 0 && check_env(s))
		ret = -1;
	free(key);
	return (ret);
}

void	mod_env(char *env, t_data *data, int pos_equal)
{
	char *key = NULL;

	if ((key = ft_substr(env, 0, pos_equal)))
	{
		remove_env(key, data);
	}
	if (key)
		free(key);
}

void	add_env(char *var, t_data *data, int pos_equal)
{
	int size;

	mod_env(var, data, pos_equal);
	size = count_elements((void **)data->my_envp);
	data->my_envp = alloc_envs((size + 1), data->my_envp);
	data->my_envp[size] = ft_strdup(var);
}

void	ft_export(char **cmd, t_data *data)
{
	int	i;
	int	pos;

	g_exit_status = 0;
	if(!cmd[1])
	{
		sort_print(data);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		if (!(pos = check_env_ex(cmd[i])))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_status = 1;
			i++;
			continue ;
		}
		if (pos > 0)
			add_env(cmd[i], data, pos);
		i++;
	}
}