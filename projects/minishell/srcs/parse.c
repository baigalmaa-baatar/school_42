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

t_process	*line_to_processes(char *line, int *nb_processes)
{
	int			i;
	char		**tmp;
	t_process	*processes;

	i = 0;
	tmp = split_pipe(line, nb_processes);
	processes = malloc(sizeof(t_process) *(*nb_processes));
	// tmp = ft_split(line, '|');
	while (tmp[i])
	{
		processes[i].params = split_param(tmp[i]);
		for (int a = 0; processes[i].params[a]; a++)
			printf("pro.p[%d] = \"%s\"\n", a, processes[i].params[a]);
		i++;
	}
	ft_free_tab(tmp);
	return (processes);
}

void	parse(char *line, char *envp[]) //not really a parsing function, it's just temporary
{
	int		i;
	char	**path;
	int		nb_processes;
	t_process	*processes;			//creating it for now, until I get it from Baigalmaa

	path = find_path();
	processes = line_to_processes(line, &nb_processes); //...and splitting cmds into process struct
	if (nb_processes == 1)
		exec_cmds(processes, path, envp);
	else								// if pipe(s) -> various cmds
		exec_pipes(processes, path, envp, nb_processes - 1);
	i = 0;
	while (i < nb_processes)
		ft_free_tab(processes[i++].params);
	free(processes);
	ft_free_tab(path);
}