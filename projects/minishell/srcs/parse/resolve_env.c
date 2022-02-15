/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:19:34 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/15 01:18:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_env_name_char(char ch, bool extended)
{
	if (ch >= 'A' && ch <= 'Z')
		return (true);
	if (ch >= 'a' && ch <= 'z')
		return (true);
	if (ch >= '0' && ch <= '9')
		return (true);
	if (ch == '_')
		return (true);
	if (extended)
		if (ch == '?')
			return (true);
	return (false);
}

bool	is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (true);
	return (false);
}

char	*find_env(char *s)
{
	int		start;
	int		len;

	len = 1;
	start = 0;
	while (s[start])
	{
		if (s[start] == '$' && is_env_name_char(s[start + 1], true))
			break ;
		start++;
	}
	if (!s[start])
		return (0);
	if (is_number(s[start + len]) || s[start + len] == '?')
		len++;
	else
	{
		while (is_env_name_char(s[start + len], false))
			len++;
	}
	if (len < 2)
		return (0);
	return (ft_substr(s, start, len));
}

char	*replace_env(char *haystack, char *needle, char *env)
{
	int		pos;
	char	*res;
	char	*substr;
	char	*prefix;

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

	result = ft_strdup(s);
	env = find_env(result);
	while (env)
	{
		if (!ft_strncmp(env, "$?\0", 3))
			env_val = ft_itoa(g_exit_status);
		else
			env_val = ft_strdup(my_getenv(&env[1], data->my_envp));
		if (!env_val)
			env_val = "";
		tmp = result;
		result = replace_env(result, env, env_val);
		free(tmp);
		free(env);
		free(env_val);
		env = find_env(result);
	}
	return (result);
}
