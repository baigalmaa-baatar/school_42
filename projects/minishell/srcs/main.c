/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:24:48 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 16:24:50 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_exit_status;

void	start_minishell(t_data *data)
{
	char	*prompt;

	prompt = "\033[96mminishell > \033[0m";
	while (1)
	{
		data->line = readline(prompt);
		if (data->line && *data->line)
		{
			if (!ft_strfind(' ', data->line))
				add_history(data->line);
			parse(data);
			free(data->line);
		}
		else if (data->line && !*data->line)
			free(data->line);
		else if (!data->line)
		{
			printf("exit\n");
			break ;
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 1)
		return (1);
	(void)argv;
	g_exit_status = 0;
	ft_memset(&data, 0, sizeof(t_data));
	init_signals(&data);
	data.my_envp = dup_envp(envp);
	data.path = find_path(data.my_envp);
	start_minishell(&data);
	rl_clear_history();
	ft_free_tab(data.my_envp);
	ft_free_tab(data.path);
	return (g_exit_status);
}
