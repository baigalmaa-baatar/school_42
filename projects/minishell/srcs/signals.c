/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:24:09 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 16:24:12 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_signals(t_data *data)
{
	ft_memset(&data->sigint, 0, sizeof(struct sigaction));
	data->sigint.sa_handler = &main_sigint_handler;
	sigaction(SIGINT, &data->sigint, NULL);
	ft_memset(&data->sigquit, 0, sizeof(struct sigaction));
	data->sigquit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &data->sigquit, NULL);
}

void	main_sigint_handler(int signum)
{
	g_exit_status = signum + 128;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	child_sigquit_handler(int signum)
{
	g_exit_status = signum;
	exit(g_exit_status);
}
