/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:45:19 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:45:21 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*eval(char *s, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;
	char	*resolved_tmp;
	char	*result;

	result = new_string(MAX_ALLOC);
	i = 0;
	j = 0;
	i = skip_spaces(s, i);
	trim_right(s);
	while (s[i])
	{
		if (s[i] == '\'')
		{
			tmp = scan_single_quoted(s, &i);
			if (!tmp)
			{
				free(s);
				free(result);
				error_fct3("Unclosed quote `", "\'\'\n", 2);
				return (0);
			}
			copy_then_free(result, &j, tmp);
		}
		else if (s[i] == '"')
		{
			tmp = scan_double_quoted(s, &i);
			if (!tmp)
			{
				free(s);
				free(result);
				error_fct3("Unclosed quote `", "\"\'\n", 2);
				return (0);
			}
			resolved_tmp = resolve_env(tmp, data);
			copy_then_free(result, &j, resolved_tmp);
			free(tmp);
		}
		else
		{
			tmp = scan_unquoted(s, &i);
			resolved_tmp = resolve_env(tmp, data);
			copy_then_free(result, &j, resolved_tmp);
			free(tmp);
		}
	}
	free(s);
	return (result);
}
