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

void	exec_cmds(t_process *process, char **path, char *envp[])
{
	int	child;
	int	built_in;

	built_in = find_built_ins(process[0].params[0]);
	if (built_in > 3)    // built-ins that shouldn't be forked
	{
		if (built_in == 4)
			ft_cd(process[0].params);
		else if (built_in == 5)
			printf("ft_export\n");  //not implemented yet
		else if (built_in == 6)
			printf("ft_unset\n");  //not implemented yet
		else if (built_in == 7)
		{
			printf("exit\n");
			ft_exit(process[0].params);
		}
		return ;
	}
	if (!built_in)
		process[0].params = find_cmds(process[0].params, path);
	if (!process[0].params)
		return ;
	child = fork();
	if (child == -1)
		error_fct("minishell: Fork failure", 6);
	if (!child)   // child process, executes commands
	{
		if (built_in == 1)
			ft_echo(process[0].params);
		else if (built_in == 2)
			ft_env(envp);
		else if (built_in == 3)
			ft_pwd();
		else if (execve(process[0].params[0], process[0].params, envp) == -1)
			error_fct("minishell: Execve failure", 7);
		exit(exit_status);
	}
	waitpid(child, &exit_status, 0);
//	exit_status = WEXITSTATUS(exit_status);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	if (WIFSIGNALED(exit_status))
		exit_status = WTERMSIG(exit_status);
	printf("\033[3;35;40m---EXIT STATUS = %d---\033[0m\n", exit_status); //temp
}
