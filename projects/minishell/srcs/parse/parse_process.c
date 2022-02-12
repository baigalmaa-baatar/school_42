/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:21:59 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:58:51 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**split(char *s, char delimiter)
{
	int		i;
	int		j;
	int		pos;
	char	**result;

	result = (char **)malloc(MAX_ALLOC * sizeof(char *));
	ft_memset(result, 0, MAX_ALLOC * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		pos = locate_char(&s[i], delimiter);
		if (pos == -1)
		{
			result[j++] = ft_strdup(&s[i]);
			break ;
		}
		else if (pos > 0)
			result[j++] = ft_substr(&s[i], 0, pos);
		else
		{
			ft_free_tab(result);
			return (0);
		}
		i += pos + 1;
	}
	return (result);
}

bool	parse_process(char *s, t_process *process, t_data *data)
{
	int		i;
	int		j;
	int		next_pos;
	int		current_pos;
	char	current_delimiter;

	current_pos = -1;
	current_delimiter = ' ';
	process->params = (char **)malloc(MAX_ALLOC * sizeof(char *));
	ft_memset(process->params, 0, MAX_ALLOC * sizeof(char *));
	i = 0;
	j = 0;
	while (i < (int)ft_strlen(s))
	{
		if (is_char_in(current_delimiter, "<>"))
			next_pos = parse_redirection(s, current_pos, process, data);
		else
		{
			next_pos = i + locate_chars(&s[i], "<> ");
			if (next_pos < i)
				next_pos = ft_strlen(s);
			if (next_pos - current_pos > 1)
			{
				process->params[j] = eval(ft_substr(s, current_pos + 1,
							next_pos - current_pos - 1), data);
				if (!process->params[j])
					return (false);
				j++;
			}
		}
		current_pos = next_pos;
		current_delimiter = s[current_pos];
		i = current_pos + 1;
	}
	return (true);
}
