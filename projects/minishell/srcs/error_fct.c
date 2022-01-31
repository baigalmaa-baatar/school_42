#include "../inc/minishell.h"

void	error_fct(t_data *data, char *msg, int exit_value)
{
	perror(msg);
	if (data)
		free_data(data);
	exit(exit_value);
}
