#include "../inc/minishell.h"

void	close_fds(t_data *data, int **pipe_fd, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (close(pipe_fd[i][0]) == -1)
			error_fct(data, "minishell: Close fd failure", 9);
		if (close(pipe_fd[i][1]) == -1)
			error_fct(data, "minishell: Close fd failure", 9);
		i++;
	}
}

void	malloc_elements(t_data *data, t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
//	ft_memset((void *)pipe_fd, 0, nb_pipes);       // necessary ?
	elements->child = malloc(sizeof(int) * (nb_pipes + 1));
	if (!elements->child)
		error_fct(data, "minishell: Malloc failure", 2);
	elements->built_in = malloc(sizeof(int) * (nb_pipes + 1));
	if (!elements->built_in)
		error_fct(data, "minishell: Malloc failure", 2);
	elements->pipe_fd = malloc(sizeof(int *) * nb_pipes);
	if (!elements->pipe_fd)
		error_fct(data, "minishell: Malloc failure", 2);
	while (i < nb_pipes)
	{
		elements->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!elements->pipe_fd[i])
			error_fct(data, "minishell: Malloc failure", 2);
	//	ft_memset((void *)pipe_fd[i], 0, 2);   // necessary ?
		if (pipe(elements->pipe_fd[i]) == -1)
		{
			close_fds(data, elements->pipe_fd, i);
			error_fct(data, "minishell: Pipe failure", 5);
		}
		i++;
	}
}

void	free_elements(t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		free(elements->pipe_fd[i]);
		i++;
	}
	free(elements->pipe_fd);
	free(elements->built_in);
	free(elements->child);
}

int	check_all_cmds(t_process *process, t_elements *elements, int nb_pipes, char **path)
{
	int	i;

	i = 0;
	while (i <= nb_pipes)
	{
		elements->built_in[i] = find_built_ins(process[i].params[0]);
		if (!elements->built_in[i])
			process[i].params = find_cmds(process[i].params, path);
		if (!process[i].params)
			return (0);
		i++;
	}
	return (1);
}

void	exec_pipes(t_data *data, int nb_pipes)
{
	int		i;
	int		j;
	int		x;
	t_elements elements;
//	int saved_stdout = dup(STDOUT_FILENO);
//	int	saved_stdin = dup(STDIN_FILENO);

	i = 0;
	j = 0;
	x = 0;
	malloc_elements(data, &elements, nb_pipes);
	if (!check_all_cmds(data->process, &elements, nb_pipes, data->path))
	{
		free_elements(&elements, nb_pipes);
		return ;
	}
	while (j <= nb_pipes)
	{
		elements.child[i] = fork();
		if (elements.child[i] == -1)
			error_fct(data, "minishell: Fork failure", 6);
		if (!elements.child[i])
		{
			if (!i)
			{
				printf("\033[3;32;40m-----------FIRST PROCESS------------\033[0m\n");
				dup2(elements.pipe_fd[i][1], 1);
				close_fds(data, elements.pipe_fd, nb_pipes);
			}
			else if (i == nb_pipes)
			{
				printf("\033[3;31;40m------------LAST PROCESS------------\033[0m\n");
				dup2(elements.pipe_fd[i - 1][0], 0);
				close_fds(data, elements.pipe_fd, nb_pipes);
			}
			else
			{
				printf("\033[3;33;40m-----------MIDDLE PROCESS-----------\033[0m\n");
				dup2(elements.pipe_fd[i - 1][0], 0);
				dup2(elements.pipe_fd[i][1], 1);
				close_fds(data, elements.pipe_fd, nb_pipes);
			}
			if (elements.built_in[i] == 1)
				ft_echo(data->process[i].params);
			else if (elements.built_in[i] == 2)
				ft_env(data->my_envp);
			else if (elements.built_in[i] == 3)
				ft_pwd(data);
			else if (elements.built_in[i] == 4)
				ft_cd(data->process[i].params);
			else if (elements.built_in[i] == 7)
				ft_exit(data->process[i].params);
			else if (execve(data->process[i].params[0], data->process[i].params, data->my_envp) == -1)
				error_fct(data, "minishell: Execve failure", 7);
			free_elements(&elements, nb_pipes);
			exit(exit_status);
		}
		i++;
		j++;
	}
	close_fds(data, elements.pipe_fd, nb_pipes);
	while (x <= nb_pipes)
	{
		waitpid(elements.child[x], &exit_status, 0);
		if (WIFEXITED(exit_status))
			exit_status = WEXITSTATUS(exit_status);
		if (WIFSIGNALED(exit_status))
			exit_status = WTERMSIG(exit_status);
	//	exit_status = WEXITSTATUS(exit_status);
		printf("\033[3;35;40m---EXIT STATUS OF PROCESS N°%d = %d---\033[0m\n", x, exit_status);
		x++;
	}
	free_elements(&elements, nb_pipes);
}
