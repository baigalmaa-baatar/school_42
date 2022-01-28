/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:19:34 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/28 04:19:37 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*find_env(char *s)
{
	int i;
	int j;
	int flag;
	char	*res = NULL;

	res = malloc(100 * sizeof(char) + 1);
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
			while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')
					|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
			{
				res[j] = s[i];
				j++;
				i++;
			}
		}
		else
			i++;
	}
	res[j] = '\0';
	if (!j)
		return (0);
	return (res);
}


char	*replace_env(char *haystack, char *needle, char *env)
{
	int pos;
	char *res;

	res = malloc (100 * sizeof(char));
	pos = find_pos(haystack, needle, ft_strlen(haystack));
	if (pos < 0)
		return (0);
	if (!pos)
		res = strjoin(env, &haystack[pos + ft_strlen(needle)]);
	else
		res = strjoin(strjoin((ft_substr(haystack, 0, pos)), env), &haystack[pos + ft_strlen(needle)]);
	return (res);
}

char	*resolve_env(char *s)
{
	char	*env;

	env = malloc(1000 * sizeof(char));
	env = find_env(s);
	if (!env)
	{
		if (ft_strlen(env) == ft_strlen(s))
			return (s);
		else
		{
			s = strjoin("", &s[ft_strlen(env)]);
			env = find_env(s);
		}
	}
	while(env)
	{
		s = replace_env(s, env, getenv(&env[1]));
		if(!s)
			break;
		env = find_env(s);
	}
	if (env)
		free(env);
	return (s);
}

// char	*check_env(char	*s) 
// {
// 	int i;
// 	int j;
// 	char	*res;

// 	i = 0;
// 	j = 0;
// 	res = malloc(1000 * sizeof(char));
// 	while(s[i])
// 	{	
// 		if (s[i] == '$')
// 			res = resolve_env(s);
// 		else
// 			res[j++] = s[i];
// 		i++;
// 	}
// 	return (res);
// }
