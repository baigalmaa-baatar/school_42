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

int	check_all_cmds(t_data *data, t_elements *elements, int nb_pipes)
{
	int	i;

	i = 0;
	while (i <= nb_pipes)
	{
		elements->built_in[i] = find_built_ins(data->process[i].params[0]);
		if (!elements->built_in[i])
			data->process[i].params = find_cmds(data->process[i].params, data);
		if (!data->process[i].params)
			return (0);
		i++;
	}
	return (1);
}

void	exec_pipes(t_data *data, int nb_pipes)
{
	int			i;
	int			x;
	t_elements	elements;
//	int saved_stdout = dup(STDOUT_FILENO);
//	int	saved_stdin = dup(STDIN_FILENO);

	i = 0;
	x = 0;
	malloc_elements(data, &elements, nb_pipes);
	if (!check_all_cmds(data, &elements, nb_pipes))
	{
		free_elements(&elements, nb_pipes);
		return ;
	}
	while (i <= nb_pipes)
	{
		elements.child[i] = fork();
		if (elements.child[i] == -1)
			error_fct(data, "minishell: Fork failure", 6);
		if (!elements.child[i])
		{
			if (!i)
			{
				printf("\033[3;32;40m-----------FIRST PROCESS------------\033[0m\n");
				if (data->process[i].fd_input > -1)
					dup2(data->process[i].fd_input, 0);
				if (data->process[i].fd_output > -1)
					dup2(data->process[i].fd_output, 1);
				else
					dup2(elements.pipe_fd[i][1], 1);
			}
			else if (i == nb_pipes)
			{
				printf("\033[3;31;40m------------LAST PROCESS------------\033[0m\n");
				if (data->process[i].fd_input > -1)
					dup2(data->process[i].fd_input, 0);
				else
					dup2(elements.pipe_fd[i - 1][0], 0);
				if (data->process[i].fd_output > -1)
					dup2(data->process[i].fd_output, 1);
			}
			else
			{
				printf("\033[3;33;40m-----------MIDDLE PROCESS-----------\033[0m\n");
				if (data->process[i].fd_input > -1)
					dup2(data->process[i].fd_input, 0);
				else
					dup2(elements.pipe_fd[i - 1][0], 0);
				if (data->process[i].fd_output > -1)
					dup2(data->process[i].fd_output, 1);
				else
					dup2(elements.pipe_fd[i][1], 1);
			}
			close_fds(data, elements.pipe_fd, i);
			if (elements.built_in[i] == 1)
				ft_echo(data->process[i].params);
			else if (elements.built_in[i] == 2)
				ft_env(data->process[0].params, data->my_envp);
			else if (elements.built_in[i] == 3)
				ft_pwd(data->my_envp);
			else if (elements.built_in[i] == 4)
				ft_cd(data->process[i].params, data);
			/*else if (elements.built_in[i] == 5)  //not implemented yet
				ft_export();
			else if (elements.built_in[i] == 6)
				ft_unset();*/
			else if (elements.built_in[i] == 7)
				ft_exit(data->process[i].params);
			else if (execve(data->process[i].params[0], data->process[i].params, data->my_envp) == -1)
				error_fct(data, "minishell: Execve failure", 7);
			free_elements(&elements, nb_pipes);
			exit(g_exit_status);
		}
		i++;
	}
	close_fds(data, elements.pipe_fd, nb_pipes);
	close_redirection_fds(data);
	while (x <= nb_pipes)
	{
		waitpid(elements.child[x], &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		if (WIFSIGNALED(g_exit_status))
			g_exit_status = WTERMSIG(g_exit_status);
	//	g_exit_status = WEXITSTATUS(g_exit_status);
		printf("\033[3;35;40m---EXIT STATUS OF PROCESS N°%d = %d---\033[0m\n", x, g_exit_status);
		x++;
	}
	free_elements(&elements, nb_pipes);
}