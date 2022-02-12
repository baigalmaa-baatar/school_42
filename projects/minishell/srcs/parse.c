/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:07:35 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 17:07:40 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	free_processes(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_processes)
	{
		if(data->process[i].params)
			ft_free_tab(data->process[i].params);
		if (data->process[i].input)
			free(data->process[i].input);
		if (data->process[i].output)
			free(data->process[i].output);
		if (data->process[i].heredoc)
			free(data->process[i].heredoc);
		i++;
	}
	free(data->process);
}

int count_elements(void **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

bool	all_space(char *s)
{
	bool	ret;
	int i;

	ret = false;
	i = 0;
	while(s[i])
	{
		if (s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	validate_redir(t_process *process)
{
	if(process->input && all_space(process->input))
		return (0);
	if(process->output && all_space(process->output))
		return (0);
	if(process->heredoc && all_space(process->heredoc))
		return (0);
	return (1);
}

bool	only_redir(char *s)
{
	size_t	size;

	size = ft_strlen(s);
	if ((s[size - 1] == '<' || s[size - 1] == '>') && s[size] == '\0')
		return (true);
	return (false);
}

t_process	*from_line_to_processes(t_data *data)
{
	int			i;
	char		**tmp;

	if(all_space(data->line))
		return (0);
	tmp = split(data->line, '|');
	if (!tmp)
	{
		error_fct3("syntax error near unexpected token `", "|'\n", 2);
		return (0);
	}
	i = 0;
	while (tmp[i])
	{
		if(all_space(tmp[i]))
		{	
			ft_free_tab(tmp);
			error_fct3("syntax error near unexpected token `", "|'\n", 2);
			return (0);
		}
		i++;
	}
	data->nb_processes = count_elements((void **)tmp);
	data->process = malloc(data->nb_processes * sizeof(t_process));
	if (!data->process)
		error_fct(data, "minishell: Malloc failure", 2);
	i = 0;
	while(i < data->nb_processes)
	{
		init_process(&data->process[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		if(only_redir(tmp[i]))
		{	
			free_processes(data);
			ft_free_tab(tmp);
			error_fct3("syntax error near unexpected token `", "newline'\n", 2);
			return (0);
		}
		if(!(parse_process(tmp[i], &data->process[i], data)))
		{
			free_processes(data);
			ft_free_tab(tmp);
			return (0);
		}
		if (!(validate_redir(&data->process[i])))
		{
			free_processes(data);
			ft_free_tab(tmp);
			error_fct3("syntax error near unexpected token `", "< or >'\n", 2);
			return (0);
		}
		if (!data->process[i].params)
			error_fct(data, "minishell: Malloc failure", 2);
		// for (int a = 0; data->process[i].params[a]; a++)
			// printf("pro.p[%d] = \"%s\"\n", a, data->process[i].params[a]);
		// printf("pro.redirection = %s, %s, %s, %d\n", data->process[i].input, data->process[i].output, data->process[i].heredoc, data->process[i].append);
		i++;
	}
	ft_free_tab(tmp);
	return (data->process);
}

void	parse(t_data *data)
{
	data->process = from_line_to_processes(data);
	if (!data->process)
		return ;
	if (!prepare_redirections(data))
		return ;
	if (data->nb_processes == 1)
		exec_cmds(data);
	else
		exec_pipes(data, data->nb_processes - 1);
	free_processes(data);
}
