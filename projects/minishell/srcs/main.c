#include "../inc/minishell.h"

int	g_exit_status;

void	main_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("\n", STDERR_FILENO);
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

void	init_signals(t_data *data)
{
	ft_memset(&data->sigint, 0, sizeof(data->sigint));
	data->sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &data->sigint, NULL);
	ft_memset(&data->sigquit, 0, sizeof(data->sigquit));
	data->sigquit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &data->sigquit, NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	t_data	data;

	if (argc != 1)		// ---> we could add an error msg
		return (1);
	(void)argv;
	g_exit_status = 0;
	init_signals(&data);
//	init_termcaps();
	data.my_envp = dup_envp(envp);
	data.path = find_path(data.my_envp);
	prompt = "\033[96mminishell > \033[0m"; // prompt (colored)
	while (1)
	{
		data.line = readline(prompt);
		if (data.line && *data.line)
		{
			if (!ft_strfind(' ', data.line))  // if there are only spaces in line, it's not added to history
				add_history(data.line);
			parse(&data);
			free(data.line);
		}
		else if (data.line && !*data.line)
			free(data.line);
		else if (!data.line)
		{
			printf("exit\n");
			break ;
		}
	}
	rl_clear_history();
	ft_free_tab(data.my_envp);
	ft_free_tab(data.path);
	return (g_exit_status);
}
