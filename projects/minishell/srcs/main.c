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

	prompt = "\001\033[96m\002minishell >\001\033[0m\002 ";
	while (1)
	{
		data->line = readline(prompt);
		if (data->line && *data->line)
		{
			add_history(data->line);
			parse(data);
			free(data->line);
			data->line = NULL;
		}
		else if (data->line && !*data->line)
		{
			free(data->line);
			data->line = NULL;
		}
		else if (!data->line)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 1)
		return (1);
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		return (1);
	(void)argv;
	g_exit_status = 0;
	ft_memset(&data, 0, sizeof(t_data));
	data.process = NULL;
	init_signals(&data);
	data.my_envp = dup_envp(envp);
	data.path = find_path(data.my_envp);
	start_minishell(&data);
	free_data(&data);
	return (g_exit_status);
}
