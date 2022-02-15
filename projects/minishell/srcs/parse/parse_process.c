/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:21:59 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:06:13 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	*new_memory(size_t size)
{
	void	*result;

	result = my_malloc(size);
	ft_memset(result, 0, size);
	return (result);
}

char	**split(char *s, char delimiter)
{
	int		i;
	int		j;
	int		pos;
	char	**result;

	result = new_memory(MAX_ALLOC * sizeof(char *));
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
		if (pos == 0)
		{
			ft_free_tab(result);
			return (0);
		}
		result[j++] = ft_substr(&s[i], 0, pos);
		i += pos + 1;
	}
	return (result);
}

int	parse_param(char *s, int pos, char **process, t_data *data)
{
	int		next_pos;

	next_pos = pos + 1 + locate_chars(&s[pos + 1], "<> ");
	if (next_pos < pos + 1)
		next_pos = ft_strlen(s);
	if (next_pos - pos > 1)
	{
		*process = eval(ft_substr(s, pos + 1, next_pos - pos - 1), data);
		if (!*process)
			return (-1);
	}
	return (next_pos);
}

bool	parse_process(char *s, t_process *process, t_data *data)
{
	int		j;
	int		pos;

	pos = -1;
	process->params = new_memory(MAX_ALLOC * sizeof(char *));
	j = 0;
	while (pos + 1 < (int)ft_strlen(s))
	{
		if (pos >= 0 && is_char_in(s[pos], "<>"))
		{
			pos = parse_redirection(s, pos, process, data);
			continue ;
		}
		pos = parse_param(s, pos, &process->params[j], data);
		if (pos < 0)
			return (false);
		if (process->params[j])
			j++;
	}
	return (true);
}
