/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:22:49 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/15 01:16:37 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_fct(t_data *data, char *msg, int exit_value)
{
	if (msg)
		perror(msg);
	if (data)
		free_data(data);
	exit(exit_value);
}

void	*my_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		exit (2);
	return (result);
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
