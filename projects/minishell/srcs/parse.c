#include "../inc/minishell.h"

int		ft_nb_occurences(char c, char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

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
	int 	stdout_copy; //only for testing purpose
	int 	stdin_copy; //only for testing purpose
	t_process last_process; //only for testing purpose

	data->process = from_line_to_processes(data);
	last_process = data->process[data->nb_processes - 1]; //only for testing purpose
	//only for testing purpose --->
	if (last_process.output)
	{
		int fd_out;
		if (last_process.append)
			fd_out = open(last_process.output, O_CREAT | O_RDWR |O_APPEND, 0644);
		else
			fd_out = open(last_process.output, O_CREAT | O_RDWR | O_TRUNC, 0644);
		stdout_copy = dup(1);
		dup2(fd_out, 1);
		close(fd_out);
	}
	if (last_process.input)
	{
		int fd_in = open(last_process.input, O_RDONLY);
		stdin_copy = dup(0);
		dup2(fd_in, 0);
		close(fd_in);
	}
	//<--- only for testing purpose
	if (data->nb_processes == 1)
		exec_cmds(data);
	else
		exec_pipes(data, data->nb_processes - 1);
	//only for testing purpose --->
	if (last_process.output)
	{
		dup2(stdout_copy, 1);
		close(stdout_copy);
	}
	if (last_process.input)
	{
		dup2(stdin_copy, 0);
		close(stdin_copy);
	}
	//<--- only for testing purpose
	i = 0;
	// while (data->process[i].params)		//deteled, because we found number of processes in previous step.
	while (i < data->nb_processes)
		ft_free_tab(data->process[i++].params);
	free(data->process);
}