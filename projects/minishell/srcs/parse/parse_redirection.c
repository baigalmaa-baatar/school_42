/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:42:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/15 01:17:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_expandable(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			return (true);
		i++;
	}
	return (false);
}

int	parse_output(char *s, int i, t_process *process, t_data *data)
{
	int	pos;

	if (s[i + 1] == '>')
	{
		array_append(&process->redirs, (void *) 4);
		i++;
	}
	else
		array_append(&process->redirs, (void *) 3);
	i = skip_spaces(s, i + 1);
	pos = i + locate_chars(&s[i], "<> ");
	if (pos < i)
		pos = ft_strlen(s);
	array_append(&process->redirs, eval(ft_substr(s, i, pos - i), data));
	return (pos);
}

int	parse_input(char *s, int i, t_process *process, t_data *data)
{
	int		pos;
	char	*filename;

	if (s[i + 1] == '<')
	{
		array_append(&process->redirs, (void *) 1);
		i++;
	}
	else
		array_append(&process->redirs, (void *) 0);
	i = skip_spaces(s, i + 1);
	pos = i + locate_chars(&s[i], "<> ");
	if (pos < i)
		pos = ft_strlen(s);
	filename = ft_substr(s, i, pos - i);
	if (process->redirs.elements[process->redirs.length - 1])
		if (is_expandable(filename))
			process->redirs.elements[process->redirs.length - 1] = (void *) 2;
	array_append(&process->redirs, eval(filename, data));
	return (pos);
}

int	parse_redirection(char *s, int i, t_process *process, t_data *data)
{
	if (s[i] == '>')
		return (parse_output(s, i, process, data));
	else
		return (parse_input(s, i, process, data));
}
