#include "../inc/minishell.h"

int	g_exit_status;

char	**dup_envp(char *envp[])
{
	int		i;
	char	**my_envp;

	i = 0;
	my_envp = malloc(sizeof(char *) * (ft_tab_len(envp) + 1));
	if (!my_envp)
		error_fct(NULL, "minishell: Malloc failure", 2);
	if (envp)
	{
		while (envp[i])
		{
			my_envp[i] = ft_strdup(envp[i]);
			if (!my_envp[i])
				error_fct(NULL, "minishell: Malloc failure", 2);
			i++;
		}
	}
	my_envp[i] = NULL;
	return (my_envp);
}
/*
void	set_data(t_data *data)
{
	data->line = NULL;
	data->path = NULL;
	data->my_envp = NULL;
	data->process = NULL;
}
*/
int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	t_data	data;

	if (argc != 1)		// ---> we could add an error msg
		return (0);
	(void)argv;
	g_exit_status = 0;
//	set_data(&data);
	data.my_envp = dup_envp(envp);
//	data.my_envp = envp;
	data.path = find_path(data.my_envp);
	prompt = "\033[96mminishell > \033[0m"; // prompt (colored)
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
	// rl_clear_history();  //Marwa, I couldn't compile, so I commented out. 
	free_data(&data);
	return (0);
}