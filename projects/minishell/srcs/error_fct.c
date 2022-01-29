#include "../inc/minishell.h"

void	error_fct(char *msg, int exit_value)
{
	perror(msg);
	exit(exit_value);
}
