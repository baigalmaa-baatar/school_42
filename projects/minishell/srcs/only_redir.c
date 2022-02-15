/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:51:14 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/16 00:34:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	only_redir(char *s)
{
	size_t	size;

	size = ft_strlen(s);
	if ((s[size - 1] == '<' || s[size - 1] == '>') && s[size] == '\0')
		return (true);
	return (false);
}

bool	all_space(char *s)
{
	bool	ret;
	int		i;

	ret = false;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	remove_faulty_processes(t_data *data)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (i < data->nb_processes)
	{
		if (data->process[i].error)
			pos = i;
		i++;
	}
	if (pos == -1)
		return ;
	i = 0;
	while (i <= pos)
		free_process(data, i++);
	i = pos + 1;
	while (i < data->nb_processes)
	{
		data->process[i - pos - 1] = data->process[i];
		init_process(&data->process[i]);
		i++;
	}
	data->nb_processes -= pos + 1;
}
