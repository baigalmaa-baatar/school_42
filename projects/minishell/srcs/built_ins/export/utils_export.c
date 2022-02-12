/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:47:24 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 15:47:25 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	find_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i])
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
	int		i;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
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
	int		pos;
	int		ret;
	char	*key;

	ret = 0;
	pos = find_equal(s);
	if (pos > 0)
	{
		key = ft_substr(s, 0, pos);
		if (check_env(key))
			ret = pos;
		free(key);
	}
	if (pos < 0 && check_env(s))
		ret = -1;
	return (ret);
}

void	mod_env(char *env, t_data *data, int pos_equal)
{
	char	*key;

	key = ft_substr(env, 0, pos_equal);
	if (key)
	{
		remove_env(key, data);
	}
	if (key)
		free(key);
}

void	add_env(char *var, t_data *data, int pos_equal)
{
	int	size;

	mod_env(var, data, pos_equal);
	size = count_elements((void **)data->my_envp);
	data->my_envp = alloc_envs((size + 1), data->my_envp);
	data->my_envp[size] = ft_strdup(var);
}
