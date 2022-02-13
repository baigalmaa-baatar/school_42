/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:42:04 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 22:49:51 by bbaatar          ###   ########.fr       */
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
			array_append(&process->output, (void *) 1);
			i++;
		}
		else
			array_append(&process->output, (void *) 0);
		i = skip_spaces(s, i + 1);
		pos = i + locate_chars(&s[i], "<> ");
		if (pos < i)
			pos = ft_strlen(s);
		array_append(&process->output, eval(ft_substr(s, i, pos - i), data));
	}
	else
	{
		if (s[i + 1] == '<')
		{
			array_append(&process->input, (void *) 1);
			i++;
		}
		else
			array_append(&process->input, (void *) 0);
		i = skip_spaces(s, i + 1);
		pos = i + locate_chars(&s[i], "<> ");
		if (pos < i)
			pos = ft_strlen(s);
		array_append(&process->input, eval(ft_substr(s, i, pos - i), data));
	}
	return (pos);
}
