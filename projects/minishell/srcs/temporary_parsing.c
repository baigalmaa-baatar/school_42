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

t_process	*line_to_processes(char *line, int nb_pipes) //temporary
{
	int			i;
	char		**tmp;
	t_process	*processes;

	i = 0;
	processes = malloc(sizeof(t_process) * (nb_pipes + 1));
	tmp = ft_split(line, '|');
	while (tmp[i])
	{
		processes[i].params = split(tmp[i]);
		i++;
	}
	ft_free_tab(tmp);
	return (processes);
}

void	parse(char *line, char *envp[]) //not really a parsing function, it's just temporary
{
	int		i;
	char	**path;
	int		nb_pipes;
	t_process	*processes;			//creating it for now, until I get it from Baigalmaa

	path = find_path();
	nb_pipes = ft_nb_occurences('|', line); //counting number of pipes in the line...
	processes = line_to_processes(line, nb_pipes); //...and splitting cmds into process struct
	if (!nb_pipes) 									//if no pipe -> one cmd
		exec_cmds(processes, path, envp);
	else								// if pipe(s) -> various cmds
		exec_pipes(processes, path, envp, nb_pipes);
	i = 0;
	while (i <= nb_pipes)
		ft_free_tab(processes[i++].params);
	free(processes);
	ft_free_tab(path);
}