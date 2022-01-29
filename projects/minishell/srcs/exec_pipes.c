#include "../inc/minishell.h"

void	close_fds(int **pipe_fd, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (close(pipe_fd[i][0]) == -1)
			error_fct("minishell: Close fd failure", 9);
		if (close(pipe_fd[i][1]) == -1)
			error_fct("minishell: Close fd failure", 9);
		i++;
	}
}

void	malloc_elements(t_elements *data, int nb_pipes)
{
	int	i;

	i = 0;
//	ft_memset((void *)pipe_fd, 0, nb_pipes);       // necessary ?
	data->child = malloc(sizeof(int) * (nb_pipes + 1));
	if (!data->child)
		error_fct("minishell: Malloc failure", 2);
	data->built_in = malloc(sizeof(int) * (nb_pipes + 1));
	if (!data->built_in)
		error_fct("minishell: Malloc failure", 2);
	data->pipe_fd = malloc(sizeof(int *) * nb_pipes);
	if (!data->pipe_fd)
		error_fct("minishell: Malloc failure", 2);
	while (i < nb_pipes)
	{
		data->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!data->pipe_fd[i])
			error_fct("minishell: Malloc failure", 2);
	//	ft_memset((void *)pipe_fd[i], 0, 2);   // necessary ?
		if (pipe(data->pipe_fd[i]) == -1)
		{
			close_fds(data->pipe_fd, i);
			error_fct("minishell: Pipe failure", 5);
		}
		i++;
	}
}

void	free_elements(t_elements *data, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		free(data->pipe_fd[i]);
		i++;
	}
	free(data->pipe_fd);
	free(data->built_in);
	free(data->child);
}

int	check_all_cmds(t_process *process, t_elements *data, int nb_pipes, char **path)
{
	int	i;

	i = 0;
	while (i <= nb_pipes)
	{
		data->built_in[i] = find_built_ins(process[i].params[0]);
		if (!data->built_in[i])
			process[i].params = find_cmds(process[i].params, path);
		if (!process[i].params)
			return (0);
		i++;
	}
	return (1);
}

void	exec_pipes(t_process *process, char **path, char *envp[], int nb_pipes)
{
	int		i;
	int		j;
	int		x;
	t_elements data;
//	int saved_stdout = dup(STDOUT_FILENO);
//	int	saved_stdin = dup(STDIN_FILENO);

	i = 0;
	j = 0;
	x = 0;
	malloc_elements(&data, nb_pipes);
	if (!check_all_cmds(process, &data, nb_pipes, path))
	{
		free_elements(&data, nb_pipes);
		return ;
	}
	while (j <= nb_pipes)
	{
		data.child[i] = fork();
		if (data.child[i] == -1)
			error_fct("minishell: Fork failure", 6);
		if (!data.child[i])
		{
			if (!i)
			{
				printf("\033[3;32;40m-----------FIRST PROCESS------------\033[0m\n");
				dup2(data.pipe_fd[i][1], 1);
				close_fds(data.pipe_fd, nb_pipes);
			}
			else if (i == nb_pipes)
			{
				printf("\033[3;31;40m------------LAST PROCESS------------\033[0m\n");
				dup2(data.pipe_fd[i - 1][0], 0);
				close_fds(data.pipe_fd, nb_pipes);
			}
			else
			{
				printf("\033[3;33;40m-----------MIDDLE PROCESS-----------\033[0m\n");
				dup2(data.pipe_fd[i - 1][0], 0);
				dup2(data.pipe_fd[i][1], 1);
				close_fds(data.pipe_fd, nb_pipes);
			}
			if (data.built_in[i] == 1)
				ft_echo(process[i].params);
			else if (data.built_in[i] == 2)
				ft_env(envp);
			else if (data.built_in[i] == 3)
				ft_pwd();
			else if (data.built_in[i] == 4)
				ft_cd(process[i].params);
			else if (data.built_in[i] == 7)
				ft_exit(process[i].params);
			else if (execve(process[i].params[0], process[i].params, envp) == -1)
				error_fct("minishell: Execve failure", 7);
			free_elements(&data, nb_pipes);
			exit(exit_status);
		}
		i++;
		j++;
	}
	close_fds(data.pipe_fd, nb_pipes);
	while (x <= nb_pipes)
	{
		waitpid(data.child[x], &exit_status, 0);
		if (WIFEXITED(exit_status))
			exit_status = WEXITSTATUS(exit_status);
		if (WIFSIGNALED(exit_status))
			exit_status = WTERMSIG(exit_status);
	//	exit_status = WEXITSTATUS(exit_status);
		printf("\033[3;35;40m---EXIT STATUS OF PROCESS N°%d = %d---\033[0m\n", x, exit_status);
		x++;
	}
	free_elements(&data, nb_pipes);
}
