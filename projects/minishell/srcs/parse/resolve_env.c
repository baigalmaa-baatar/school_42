/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:19:34 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/04 00:22:31 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*find_env(char *s)
{
	int i;
	int j;
	int flag;
	char	*res = NULL;

	res  = new_string(ft_strlen(s));
	i = 0;
	j = 0;
	flag = 0;
	while(s[i])
	{
		if (flag == 0 && s[i] == '$')
		{
			i++;
			flag++;
			res[j++] = '$';
			if ((s[i] >= '0' && s[i] <= '9') || s[i] == '?')
			{
				res[j] = s[i];
				return (res);
			}
			while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
			{
				res[j] = s[i];
				j++;
				i++;
			}
		}
		else
			i++;
	}
	if (j < 2)
	{
		free(res);
		return (0);
	}
	return (res);
}

char	*replace_env(char *haystack, char *needle, char *env)
{
	int pos;
	char *res;
	char *substr;
	char *prefix;

	pos = find_pos(haystack, needle, ft_strlen(haystack));
	if (pos < 0)
		return (ft_strdup(haystack));
	if (!pos)
		return (strjoin(env, &haystack[ft_strlen(needle)]));
	substr = ft_substr(haystack, 0, pos);
	prefix = strjoin((substr), env);
	res = strjoin(prefix, &haystack[pos + ft_strlen(needle)]);
	free(substr);
	free(prefix);
	return (res);
}

char	*resolve_env(char *s, t_data *data)
{
	char	*env;
	char	*result;
	char	*env_val;
	char	*tmp;

	(void)data;
	result = ft_strdup(s);
	while((env = find_env(result)))
	{
		if (!ft_strncmp(env, "$?\0", 3))
			env_val = ft_itoa(g_exit_status);
		else
			env_val = my_getenv(&env[1], data->my_envp);
		if (!env_val)
			env_val = "";
		tmp = result;
		result = replace_env(result, env, env_val);
		free(tmp);
		free(env);
	}
	return (result);
}
