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

bool	is_char_in(char ch, char *delimiters)
{
	while (*delimiters)
	{
		if (ch == *delimiters)
			return (true);
		delimiters++;
	}

	return (false);
}

int		locate_chars(char *s, char *delimiters)
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
		else if (open == 0 && is_char_in(s[i], delimiters))
			return (i);
		i++;
	}
	return (-1);
}

int		locate_char(char *s, char delimiter)
{
	char delimiters[2];

	delimiters[0] = delimiter;
	delimiters[1] = 0;
	return (locate_chars(s, delimiters));
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
		else
		{
			ft_free_tab(result);
			return (0);
		}
		i += pos + 1;
	}
	return (result);
}

int		parse_redirection(char *s, int i, t_process *process, t_data *data)
{
	int pos;

	if (s[i] == '>')
	{
		// output
		if (s[i + 1] == '>')
		{
			// append
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
			// heredoc
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
			// input
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

bool	parse_process(char *s, t_process *process, t_data *data)
{
	int		i;
	int		j;
	int		next_pos;
	int		current_pos;
	char	current_delimiter;

	// init_process(process);
	current_pos = -1;
	current_delimiter = ' ';
	process->params = (char **)malloc(MAX_ALLOC * sizeof(char *));
	memset(process->params, 0, MAX_ALLOC * sizeof(char *));
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
				process->params[j] = eval(ft_substr(s, current_pos + 1, next_pos - current_pos - 1), data);
				if (!process->params[j])
				{
					free_t(process->params);
					return (false);
				}
				j++;
			}
		}
		current_pos = next_pos; // TODO: current_pos can replaced with i - 1, or i can be replaced with current_pos + 1
		current_delimiter = s[current_pos]; // current_delimiter can be replaced with s[current_pos]
		i = current_pos + 1;
	}
	return (true);
}
