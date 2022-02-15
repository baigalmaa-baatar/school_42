/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:07:35 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/16 00:31:14 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_all_space(char **tmp)
{
	int	i;

	if (!tmp)
	{
		error_fct3("syntax error near unexpected token `", "|'\n", 2);
		return (0);
	}
	i = 0;
	while (tmp[i])
	{
		if (all_space(tmp[i]))
		{
			ft_free_tab(tmp);
			error_fct3("syntax error near unexpected token `", "|'\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	free_data_s(char **tmp, t_data *data)
{
	free_processes(data);
	ft_free_tab(tmp);
	return (0);
}

int	prepare_parse(char **tmp, t_data *data)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (only_redir(tmp[i]))
		{
			error_fct3("syntax error near unexpected token `", "newline'\n", 2);
			return (free_data_s(tmp, data));
		}
		if (!(parse_process(tmp[i], &data->process[i], data)))
			return (free_data_s(tmp, data));
		if (!(validate_redir(&data->process[i])))
		{
			error_fct3("syntax error near unexpected token `", "< or >'\n", 2);
			return (free_data_s(tmp, data));
		}
		if (!data->process[i].params)
			error_fct(data, "minishell: Malloc failure", 2);
		i++;
	}
	return (1);
}

t_process	*from_line_to_processes(t_data *data)
{
	int		i;
	char	**tmp;

	if (all_space(data->line))
		return (0);
	tmp = split(data->line, '|');
	if (!check_all_space(tmp))
		return (0);
	data->nb_processes = count_elements((void **)tmp);
	data->process = malloc(data->nb_processes * sizeof(t_process));
	if (!data->process)
		error_fct(data, "minishell: Malloc failure", 2);
	i = 0;
	while (i < data->nb_processes)
	{
		init_process(&data->process[i]);
		i++;
	}
	if (!prepare_parse(tmp, data))
		return (0);
	ft_free_tab(tmp);
	return (data->process);
}

void	parse(t_data *data)
{
	data->process = from_line_to_processes(data);
	if (!data->process)
		return ;
	prepare_redirections(data);
	remove_faulty_processes(data);
	if (data->nb_processes == 1)
		exec_cmds(data);
	else if (data->nb_processes > 1)
		exec_pipes(data, data->nb_processes - 1);
	free_processes(data);
}
