#include "../inc/minishell.h"

void	error_fct(t_data *data, char *msg, int exit_value)
{
	perror(msg);
	if (data)
		free_data(data);
	exit(exit_value);
}

void	error_fct2(char *msg, int exit_value)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	g_exit_status = exit_value;
}

void	error_fct3(char *msg, char *err_str, int exit_value)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(err_str, 2);
	g_exit_status = exit_value;
}