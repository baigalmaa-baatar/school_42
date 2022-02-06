#include "../inc/minishell.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	ft_free_tab(data->path);
	ft_free_tab(data->my_envp);
	free(data->line);
	while (i < data->nb_processes)	//changed i to nb_processes
		ft_free_tab(data->process[i++].params);
	free(data->process);
	// rl_clear_history();   //Marwa, I couldn't compile, so I commented out. 
}
