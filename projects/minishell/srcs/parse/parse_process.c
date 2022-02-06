/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:21:59 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/04 00:22:05 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	trim_right(char *s)
{
	int len;

	len = ft_strlen(s);
	while (len > 0 && s[len - 1] == ' ')
	{
		s[len - 1] = 0;
		len--;
	}
}

char	*new_string(int capacity)
{
	char *result;

	capacity += 1;
	result = (char *)malloc(capacity * sizeof(char));
	memset(result, 0, capacity * sizeof(char));

	return result;
}

int		locate_char(char *s, char ch)
{
	int i;
	char open;
	bool escape;

	i = 0;
	open = 0;
	escape = false;
	while (s[i])
	{
		if (escape)
		{
			escape = false;
			i++;
			continue;
		}
		if (s[i] == '"' || s[i] == '\'')
		{
			if (open == 0)
				open = s[i];
			else if (open == s[i])
				open = 0;
		} else if (s[i] == '\\')
			escape = true;
		else if (open == 0 && s[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

char	**split(char *s, char delimiter)
{
	int		i;
	int		j;
	int		pos;
	char	**result;

	result = (char **)malloc(MAX_ALLOC * sizeof(char *));
	memset(result, 0, MAX_ALLOC * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		pos = locate_char(&s[i], delimiter);
		if (pos == -1)
		{
			result[j++] = ft_strdup(&s[i]);
			break;
		}
		else if (pos > 0)
			result[j++] = ft_substr(&s[i], 0, pos);
		i += pos + 1;
	}
	return (result);
}

char	*scan_single_quoted(char *s, int *i)
{
	int j;
	char *result;

	result = new_string(ft_strlen(s));
	(*i)++;
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '\'')
		{
			(*i)++;
			return (result);
		}
		result[j++] = s[(*i)++];
	}
	free(result);
	return (NULL);
}

char	*scan_double_quoted(char *s, int *i)
{
	int j;
	char *result;

	result = new_string(ft_strlen(s));
	(*i)++;
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '\\')
		{
			if (s[*i + 1] == '$' || s[*i + 1] == '`' || s[*i + 1] == '"' || s[*i + 1] == '\\')
				(*i)++;
		}
		else if (s[*i] == '"')
		{
			(*i)++;
			return (result);
		}
		result[j++] = s[(*i)++];
	}
	free(result);
	return (NULL);
}

char	*scan_unquoted(char *s, int *i)
{
	int j;
	char *result;

	result = new_string(ft_strlen(s));
	j = 0;
	while (s[*i])
	{
		if (s[*i] == '\'' || s[*i] == '"')
			return (result);
		else if (s[*i] == '\\' && s[*i + 1] != 0)
			(*i)++;
		result[j++] = s[(*i)++];
	}

	return (result);
}

void copy_then_free(char *src, int *i, char *dst)
{
	int j;

	j = 0;
	while (dst[j])
		src[(*i)++] = dst[j++];
	free(dst);
}

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
			copy_then_free(result, &j, tmp);
		}
		else if (s[i] == '"')
		{
			tmp = scan_double_quoted(s, &i);
			resolved_tmp = resolve_env(tmp, data);
			copy_then_free(result, &j, resolved_tmp);
			free(tmp);
		} else
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

void	init_process(t_process *process)
{
	process->params = NULL;
	process->input = NULL;
	process->output = NULL;
	process->heredoc = NULL;
	process->append = false;
	process->fd_input = -1;
	process->fd_output = -1;
}

int		locate_redirection_char(char *s)
{
	int pos;
	int tmp;

	pos = ft_strlen(s);
	tmp = locate_char(s, '<');
	if (tmp != -1)
		pos = tmp;
	tmp = locate_char(s, '>');
	if (tmp != -1 && tmp < pos)
		pos = tmp;
	return (pos);
}

bool	parse_params(char *s, t_process *process, t_data *data)
{
	int i;

	process->params = split(s, ' ');
	if (process->params == NULL)
		return (false);

	i = 0;
	while (process->params[i])
	{
		process->params[i] = eval(process->params[i], data);
		i++;
	}

	return (true);
}

void	parse_redirections(char *s, t_process *process, t_data *data)
{
	int i;
	int tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			// output
			if (s[i + 1] == '>')
			{
				// append
				process->append = true;
				i++;
			}
			tmp = locate_redirection_char(&s[i + 1]);
			process->output = eval(ft_substr(&s[i + 1], 0, tmp), data);
		}
		else
		{
			if (s[i + 1] == '<')
			{
				// heredoc
				i++;
				tmp = locate_redirection_char(&s[i + 1]);
				process->heredoc = eval(ft_substr(&s[i + 1], 0, tmp), data);
			}
			else
			{
				// input
				tmp = locate_redirection_char(&s[i + 1]);
				process->input = eval(ft_substr(&s[i + 1], 0, tmp), data);
			}
		}
		i += tmp + 1;
	}
}

bool	parse_process(char *s, t_process *process, t_data *data)
{
	int tmp;
	char *params;
	char *redirections;

	init_process(process);
	tmp = locate_redirection_char(s);
	params = ft_substr(s, 0, tmp);
	redirections = ft_substr(s, tmp, ft_strlen(s) - tmp);

	if (!parse_params(params, process, data))
	{
		free(params);
		free(redirections);
		return (false);
	}
	parse_redirections(redirections, process, data);
	free(params);
	free(redirections);

	return (true);
}