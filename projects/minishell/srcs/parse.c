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

t_process	*from_line_to_processes(t_data *data, int *nb_processes)
{
	int			i;
	char		**tmp;
	t_process	*processes;

	i = 0;
	tmp = split_pipe(data->line, nb_processes);
	if (!tmp)
		error_fct(data, "minishell: Malloc failure", 2);
	processes = malloc(sizeof(t_process) * (*nb_processes + 1));
	if (!processes)
		error_fct(data, "minishell: Malloc failure", 2);
	while (tmp[i])
	{
		processes[i].params = split_param(tmp[i]);
		if (!processes[i].params)
			error_fct(data, "minishell: Malloc failure", 2);
		for (int a = 0; processes[i].params[a]; a++)
			printf("pro.p[%d] = \"%s\"\n", a, processes[i].params[a]);
		i++;
	}
	processes[i].params = NULL;
	ft_free_tab(tmp);
	return (processes);
}

void	parse(t_data *data)
{
	int		i;
	int		nb_process;

	data->process = from_line_to_processes(data, &nb_process);
	if (nb_process == 1)
		exec_cmds(data);
	else
		exec_pipes(data, nb_process - 1);
	i = 0;
	while (data->process[i].params)
		ft_free_tab(data->process[i++].params);
	free(data->process);
}