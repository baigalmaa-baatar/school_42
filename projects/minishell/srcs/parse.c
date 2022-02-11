#include "../inc/minishell.h"

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

t_process	*from_line_to_processes(t_data *data)
{
	int			i;
	char		**tmp;
	t_process	*processes;

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
	processes = malloc(data->nb_processes * sizeof(t_process));
	if (!processes)
		error_fct(data, "minishell: Malloc failure", 2);
	i = 0;
	while(i < data->nb_processes)
	{
		init_process(&processes[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		if(!(parse_process(tmp[i], &processes[i], data)))
		{
			free(processes);
			ft_free_tab(tmp);
			return (0);
		}
		if (!processes[i].params)
			error_fct(data, "minishell: Malloc failure", 2);
		for (int a = 0; processes[i].params[a]; a++)
			printf("pro.p[%d] = \"%s\"\n", a, processes[i].params[a]);
		printf("pro.redirection = %s, %s, %s, %d\n", processes[i].input, processes[i].output, processes[i].heredoc, processes[i].append);
		i++;
	}
	ft_free_tab(tmp);
	return (processes);
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
