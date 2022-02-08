#include "../inc/minishell.h"

void child_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	exit(g_exit_status);
}

void child_sigquit_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	exit(g_exit_status);
}

void	exec_no_built_in(t_data *data)
{
	int	child;
	struct sigaction sig;
	struct sigaction sigquit;

	data->process[0].params = find_cmds(data->process[0].params, data);
	if (!data->process[0].params)
		return ;
	child = fork();
	if (child == -1)
		error_fct(data, "minishell: Fork failure", 6);
	if (!child)   // child process, executes commands that are not built-ins
	{
		sig.sa_handler = &child_sigint_handler;
		sigaction(SIGINT, &sig, NULL);
		sigquit.sa_handler = &child_sigquit_handler;
		sigaction(SIGQUIT, &sigquit, NULL);
		if (data->process[0].params)
		{
			if (execve(data->process[0].params[0], data->process[0].params, data->my_envp) == -1)
				error_fct(data, "minishell: Execve failure", 7);
		}
		free_data(data);
		exit(g_exit_status);
	}
	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
	waitpid(child, &g_exit_status, 0);
	sig.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &sig, NULL);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	if (WIFSIGNALED(g_exit_status))
		g_exit_status = WTERMSIG(g_exit_status);
//	printf("\033[3;35;40m---EXIT STATUS = %d---\033[0m\n", g_exit_status); //temp
}

void	exec_cmds(t_data *data)
{
	int	built_in;
	int stdin_copy;
	int stdout_copy;

	if (!data->process[0].params[0])
		return ;
	if (data->process[0].fd_input > -1)
	{
		stdin_copy = dup(0);
		dup2(data->process[0].fd_input, 0);
	}
	if (data->process[0].fd_output > -1)
	{
		stdout_copy = dup(1);
		dup2(data->process[0].fd_output, 1);
	}

	built_in = find_built_ins(data->process[0].params[0]);
	if (built_in)    // built-ins : shouldn't be forked (if no pipe)
	{
		if (built_in == 1)
			ft_echo(data->process[0].params);
		else if (built_in == 2)
			ft_env(data->process[0].params, data->my_envp);
		else if (built_in == 3)
			ft_pwd(data->my_envp);
		else if (built_in == 4)
			ft_cd(data->process[0].params, data);
		else if (built_in == 5)
			ft_export(data->process[0].params, data);
		else if (built_in == 6)
			ft_unset(data->process[0].params, data);
		else if (built_in == 7)
		{
			printf("exit\n");
			ft_exit(data->process[0].params);
		}
	//	printf("\033[3;35;40m---EXIT STATUS = %d---\033[0m\n", g_exit_status); //temp
	}
	else
		exec_no_built_in(data);
	if (data->process[0].fd_input > -1)
		dup2(stdin_copy, 0);
	if (data->process[0].fd_output > -1)
		dup2(stdout_copy, 1);
	close_redirection_fds(data);
}