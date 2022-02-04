#include "../inc/minishell.h"

void	exec_cmds(t_data *data)
{
	int	child;
	int	built_in;

	built_in = find_built_ins(data->process[0].params[0]);
	if (built_in > 3)    // built-ins that shouldn't be forked
	{
		if (built_in == 4)
			ft_cd(data->process[0].params, data);
		else if (built_in == 5)
			printf("ft_export\n");  //not implemented yet
		else if (built_in == 6)
			printf("ft_unset\n");  //not implemented yet
		else if (built_in == 7)
		{
			printf("exit\n");
			ft_exit(data->process[0].params);
		}
		return ;
	}
	if (!built_in)
		data->process[0].params = find_cmds(data->process[0].params, data);
	if (!data->process[0].params)
		return ;
	child = fork();
	if (child == -1)
		error_fct(data, "minishell: Fork failure", 6);
	if (!child)   // child process, executes commands
	{
		if (built_in == 1)
			ft_echo(data->process[0].params);
		else if (built_in == 2)
			ft_env(data->process[0].params, data->my_envp);
		else if (built_in == 3)
			ft_pwd();
		else if (execve(data->process[0].params[0], data->process[0].params, data->my_envp) == -1)
			error_fct(data, "minishell: Execve failure", 7);
		free_data(data);
		exit(g_exit_status);
	}
	waitpid(child, &g_exit_status, 0);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	if (WIFSIGNALED(g_exit_status))
		g_exit_status = WTERMSIG(g_exit_status);
	printf("\033[3;35;40m---EXIT STATUS = %d---\033[0m\n", g_exit_status); //temp
}
