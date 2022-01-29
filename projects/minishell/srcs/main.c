#include "../inc/minishell.h"

int	exit_status;

char	**dup_envp(char *envp[])
{
	int		i;
	char	**my_envp;

	i = 0;
	my_envp = malloc(sizeof(char *) * (ft_tab_len(envp) + 1));
	if (!my_envp)
		error_fct("minishell: Malloc failure", 2);
	while (envp[i])
	{
		my_envp[i] = ft_strdup(envp[i]);
		if (!my_envp[i])
			error_fct("minishell: Malloc failure", 2);
		i++;
	}
	my_envp[i] = NULL;
	return (my_envp);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*line;
	char	*prompt;
	char	**my_envp;

	if (argc != 1)
		return (0);
	(void)argv;
	exit_status = 0;
	my_envp = dup_envp(envp);      // not sure about this yet
	prompt = "\033[96mMinishell > \033[0m"; // prompt (colored)
	while (1)
	{
		line = readline(prompt);
		if (*line)
		{
			add_history(line);
			parse(line, envp);  //uses envp for now, may have to change it to my_envp
			free(line);
		}
		line = NULL;
	}
	ft_free_tab(my_envp);
	return (0);
}