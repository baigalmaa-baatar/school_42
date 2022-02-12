/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:42:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 14:42:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parse_redirection(char *s, int i, t_process *process, t_data *data)
{
	int	pos;

	if (s[i] == '>')
	{
		if (s[i + 1] == '>')
		{
			process->append = true;
			i++;
		}
		i = skip_spaces(s, i + 1);
		pos = i + locate_chars(&s[i], "<> ");
		if (pos < i)
			pos = ft_strlen(s);
		if (process->output)
			free(process->output);
		process->output = eval(ft_substr(s, i, pos - i), data);
	}
	else
	{
		if (s[i + 1] == '<')
		{
			i++;
			i = skip_spaces(s, i + 1);
			pos = i + locate_chars(&s[i], "<> ");
			if (pos < i)
				pos = ft_strlen(s);
			if (process->heredoc)
				free(process->heredoc);
			process->heredoc = eval(ft_substr(s, i, pos - i), data);
		}
		else
		{
			i = skip_spaces(s, i + 1);
			pos = i + locate_chars(&s[i], "<> ");
			if (pos < i)
				pos = ft_strlen(s);
			if (process->input)
				free(process->input);
			process->input = eval(ft_substr(s, i, pos - i), data);
		}
	}
	return (pos);
}
