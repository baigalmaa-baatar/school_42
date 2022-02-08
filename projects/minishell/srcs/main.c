#include "../inc/minishell.h"

int	g_exit_status;
/*
void sig_handler(int signum)
{
	printf("\nInside handler function\n");
	printf("signum = %d\n", signum);
//	signal(SIGINT, SIG_DFL);
}
*/
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

void	init_termcaps()
{
	int		i;
	char *bp = malloc(sizeof(char) * 2048);
	char *area = NULL;

	i = 0;
	if (tgetent(bp, getenv("TERM")) != 1)
		return (-1);
	printf("return tgetflag = %d\n", tgetflag("li"));
	printf("return tgetnum = %d\n", tgetnum("co"));
	char	*ret1 = tgetstr("md", &area);
	char	*ret2 = tgetstr("me", &area);
//	tputs(tgoto(tgetstr("cm", NULL), 20, 20), 1, ft_putchar);
		tputs(ret1, 1, ft_putchar);

		tputs(ret2, 1, ft_putchar);
	}
}
*/

int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	char	*input;
	char	**lines;
	int		i = 0;
	t_data	data;

	if (argc != 1)		// ---> we could add an error msg
		return (0);
	(void)argv;
	g_exit_status = 0;
	data.my_envp = dup_envp(envp);
//	data.my_envp = envp;
	data.path = find_path(data.my_envp);
//	init_termcaps();
	prompt = "\033[96mminishell > \033[0m"; // prompt (colored)
	while (1)
	{
		input = readline(prompt);
		lines = split(input, ';');
		free(input);
		i = 0;
		while (lines[i])
		{
			data.line = lines[i];
			add_history(data.line);
			parse(&data);
			data.line = NULL;
			i++;
		}
		ft_free_tab(lines);
	}
	// rl_clear_history();  //Marwa, I couldn't compile, so I commented out.
	ft_free_tab(data.my_envp);
	ft_free_tab(data.path);
	return (0);
}

