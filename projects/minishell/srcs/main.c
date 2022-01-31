#include "../inc/minishell.h"

int	exit_status;

char	**dup_envp(char *envp[])
{
	int		i;
	char	**my_envp;

	i = 0;
	my_envp = malloc(sizeof(char *) * (ft_tab_len(envp) + 1));
	if (!my_envp)
		error_fct(NULL, "minishell: Malloc failure", 2);
	while (envp[i])
	{
		my_envp[i] = ft_strdup(envp[i]);
		if (!my_envp[i])
			error_fct(NULL, "minishell: Malloc failure", 2);
		i++;
	}
	my_envp[i] = NULL;
	return (my_envp);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	t_data	data;

	if (argc != 1)
		return (0);
	(void)argv;
	exit_status = 0;
	data.my_envp = dup_envp(envp);      // not sure about this yet
//	data.my_envp = envp;
	data.path = find_path();
	prompt = "\033[96mMinishell > \033[0m"; // prompt (colored)
	while (1)
	{
		data.line = readline(prompt);
		if (*data.line)
		{
			add_history(data.line);
			parse(&data);
			free(data.line);
		}
		data.line = NULL;
	}
	// rl_clear_history();
	ft_free_tab(data.my_envp);
	ft_free_tab(data.path);
	return (0);
}