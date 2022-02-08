#include "../inc/minishell.h"

int	g_exit_status;

void	main_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

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
/*
int	ft_putchar(int c)
{
	char a = c;
	write(1, &a, 1);
	return (0);
}

void	init_termcaps()
{
	int		i;
//	char 	*bp;
	//char 	*area = NULL;

	i = 0;
//	bp = malloc(sizeof(char) * 2048);
//	if (!bp)
//		error_fct(NULL, "minishell: Malloc failure", 2);
	if (tgetent(NULL, getenv("TERM")) != 1)
	{
//		free(bp);
		return ;
	}
	printf("return tgetflag = %d\n", tgetflag("li"));
	printf("return tgetnum = %d\n", tgetnum("co"));
//	char	*ret1 = tgetstr("ce", &area);
//	char	*ret2 = tgetstr("md", &area);
//	tputs(tgoto(tgetstr("cm", NULL), 20, 20), 1, ft_putchar);
//	tputs(ret1, 1, ft_putchar);
//	tputs(ret2, 1, ft_putchar);
}
*/

int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
/*	char	*input;
	char	**lines;
	int		i = 0;*/
	t_data	data;
	struct sigaction sigint;
	struct sigaction sigquit;

	sigquit.sa_handler = SIG_IGN;
	sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	if (argc != 1)		// ---> we could add an error msg
		return (1);
	(void)argv;
	g_exit_status = 0;
//	init_termcaps();
	data.my_envp = dup_envp(envp);
	data.path = find_path(data.my_envp);
	prompt = "\033[96mminishell > \033[0m"; // prompt (colored)
	while (1)
	{
	/*	input = readline(prompt);
		lines = split(input, ';');
		free(input);
		i = 0;
		while (lines[i])
		{
			add_history(data.line);
			parse(&data);
			free(data.line);
			data.line = NULL;
		}
		ft_free_tab(lines);
		*/
		data.line = readline(prompt);
		if (data.line && *data.line)
		{
			if (!ft_strfind(' ', data.line))  // if there are only spaces in line, it's not added to history
				add_history(data.line);
			parse(&data);
			free(data.line);
			data.line = NULL;
		}
		else if (!data.line)
			break ;
	}
	// rl_clear_history();  //Marwa, I couldn't compile, so I commented out.
	ft_free_tab(data.my_envp);
	ft_free_tab(data.path);
	return (0);
}

