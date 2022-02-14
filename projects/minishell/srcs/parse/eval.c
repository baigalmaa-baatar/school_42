/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:45:19 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/13 19:04:48 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

typedef struct s_eval_params
{
	char	*input;
	int		*input_pos;
	char	*output;
	int		*output_pos;
}			t_eval_params;

t_eval_params	build_eval_params(char *input, char *output,
	int *input_pos, int *output_pos)
{
	t_eval_params	result;

	*input_pos = 0;
	*output_pos = 0;
	result.input = input;
	result.input_pos = input_pos;
	result.output = output;
	result.output_pos = output_pos;
	return (result);
}

int	eval_single_quoted(t_eval_params eval_params)
{
	char	*tmp;

	tmp = scan_single_quoted(eval_params.input, eval_params.input_pos);
	if (!tmp)
	{
		free(eval_params.input);
		free(eval_params.output);
		error_fct3("Unclosed quote `", "\'\'\n", 2);
		return (0);
	}
	copy_then_free(eval_params.output, eval_params.output_pos, tmp);
	return (1);
}

int	eval_double_quoted(t_data *data, t_eval_params eval_params)
{
	char	*tmp;
	char	*resolved_tmp;

	tmp = scan_double_quoted(eval_params.input, eval_params.input_pos);
	if (!tmp)
	{
		free(eval_params.input);
		free(eval_params.output);
		error_fct3("Unclosed quote `", "\"\'\n", 2);
		return (0);
	}
	resolved_tmp = resolve_env(tmp, data);
	copy_then_free(eval_params.output, eval_params.output_pos, resolved_tmp);
	free(tmp);
	return (1);
}

void	eval_unquoted(t_data *data, t_eval_params eval_params)
{
	int		i;
	char	*tmp;
	char	*resolved_tmp;
	char	*space_emit;

	tmp = scan_unquoted(eval_params.input, eval_params.input_pos);
	resolved_tmp = resolve_env(tmp, data);
	i = skip_spaces(resolved_tmp, 0);
	space_emit = ft_substr(resolved_tmp, i, ft_strlen(resolved_tmp) - i);
	copy_then_free(eval_params.output, eval_params.output_pos, space_emit);
	free(tmp);
	free(resolved_tmp);
}

char	*eval(char *s, t_data *data)
{
	int				i;
	int				j;
	char			*result;
	t_eval_params	eval_params;

	result = new_string(MAX_ALLOC);
	eval_params = build_eval_params(s, result, &i, &j);
	i = trim(s);
	while (s[i])
	{
		if (s[i] == '\'')
		{
			if (!eval_single_quoted(eval_params))
				return (0);
		}
		else if (s[i] == '"')
		{
			if (!eval_double_quoted(data, eval_params))
				return (0);
		}
		else
			eval_unquoted(data, eval_params);
	}
	free(s);
	return (result);
}
