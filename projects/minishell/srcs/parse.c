#include "../inc/minishell.h"

int count_elements(void **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

t_process	*from_line_to_processes(t_data *data)
{
	int			i;
	char		**tmp;
	t_process	*processes;

	i = 0;
	tmp = split(data->line, '|');
	if (!tmp)
		error_fct(data, "minishell: Malloc failure", 2);
	// processes = malloc(sizeof(t_process) * (*nb_processes + 1));  created a funciton "count_elements" to find number of processes
	data->nb_processes = count_elements((void **)tmp);
	processes = malloc(data->nb_processes * sizeof(t_process));
	if (!processes)
		error_fct(data, "minishell: Malloc failure", 2);
	while (tmp[i])
	{
		// processes[i].params = split_param(tmp[i], data); deleted and changed to "parse_process" function
		parse_process(tmp[i], &processes[i], data);
		if (!processes[i].params)
			error_fct(data, "minishell: Malloc failure", 2);
		for (int a = 0; processes[i].params[a]; a++)
			printf("pro.p[%d] = \"%s\"\n", a, processes[i].params[a]);
		printf("pro.redirection = %s, %s, %s, %d\n", processes[i].input, processes[i].output, processes[i].heredoc, processes[i].append);
		i++;
	}
	// processes[i].params = NULL; //deleted, because we don't use it.
	ft_free_tab(tmp);
	return (processes);
}

void	parse(t_data *data)
{
	int		i;

	data->process = from_line_to_processes(data);
	if (!prepare_redirections(data))
	{
		// Got an error when preparing redirections, probably one of the input/output file wasn't accessible.
		// We should print an error.
		return;
	}
	if (data->nb_processes == 1)
		exec_cmds(data);
	else
		exec_pipes(data, data->nb_processes - 1);

	i = 0;
	// while (data->process[i].params)		//deteled, because we found number of processes in previous step.
	while (i < data->nb_processes)
	{
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