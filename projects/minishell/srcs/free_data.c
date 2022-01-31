#include "../inc/minishell.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	ft_free_tab(data->path);
//	ft_free_tab(data->my_envp);
	free(data->line);
	while (data->process[i].params)
		ft_free_tab(data->process[i++].params);
	free(data->process);
	// rl_clear_history();
}
