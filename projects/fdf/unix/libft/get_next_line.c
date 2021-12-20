/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:26:33 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/18 16:38:50 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_char(int fd, char *ch)
{
	static char	buff[1000];
	static int	i = 0;
	static int	fd_result = 0;

	if (i < fd_result)
	{
		*ch = buff[i++];
		return (1);
	}
	fd_result = read(fd, buff, 1000);
	if (fd_result <= 0)
	{	
		return (fd_result);
	}
	i = 0;
	*ch = buff[i++];
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	char		*result;
	int			ret_val;
	static char	tmp_buff[32000];

	if (fd < 0 || !line)
		return (-1);
	i = 0;
	while (1)
	{
		ret_val = get_next_char(fd, &tmp_buff[i]);
		if (ret_val < 0)
			return (-1);
		if (tmp_buff[i] == '\n' || !ret_val)
			break ;
		i++;
	}
	tmp_buff[i] = '\0';
	result = ft_strdup(tmp_buff);
	*line = &result[0];
	if (!ret_val)
		return (0);
	return (1);
}
