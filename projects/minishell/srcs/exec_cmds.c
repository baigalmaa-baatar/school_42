#include "../inc/minishell.h"

int	find_built_ins(char *cmd)  //returns a code for each built-in, 0 if no built-in
{
	if (ft_strnstr(cmd, "echo", 4) && !cmd[4])
		return (1);
	if (ft_strnstr(cmd, "env", 3) && !cmd[3])
		return (2);
	if (ft_strnstr(cmd, "pwd", 3) && !cmd[3])
		return (3);
	if (ft_strnstr(cmd, "cd", 2) && !cmd[2])
		return (4);
	if (ft_strnstr(cmd, "export", 6) && !cmd[6])
		return (5);
	if (ft_strnstr(cmd, "unset", 5) && !cmd[5])
		return (6);
	if (ft_strnstr(cmd, "exit", 4) && !cmd[4])
		return (7);
	return (0);
}

void	exec_cmds(t_data *data)
{
	int	child;
	int	built_in;

	built_in = find_built_ins(data->process[0].params[0]);
	if (built_in > 3)    // built-ins that shouldn't be forked
	{
		if (built_in == 4)
			ft_cd(data->process[0].params);
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
		data->process[0].params = find_cmds(data->process[0].params, data->path);
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
			ft_env(data->my_envp);
		else if (built_in == 3)
			ft_pwd(data);
		else if (execve(data->process[0].params[0], data->process[0].params, data->my_envp) == -1)
			error_fct(data, "minishell: Execve failure", 7);
		free_data(data);
		exit(exit_status);
	}
	waitpid(child, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	if (WIFSIGNALED(exit_status))
		exit_status = WTERMSIG(exit_status);
	printf("\033[3;35;40m---EXIT STATUS = %d---\033[0m\n", exit_status); //temp
}
