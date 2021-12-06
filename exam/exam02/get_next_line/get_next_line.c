/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:17:44 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/06 14:17:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	int	i;
	char	*result;

	result = (char	*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int get_next_line(char **line)
{
    int	i;
	char	*result;
	int	ret_val;
	static char buff[32000];

	if (!line)
		return (-1);
	i = 0;
	while (1)
	{
		ret_val = read(0, &buff[i], 1);
		if (ret_val < 0)
			return (-1);
		if (buff[i] == '\n' || !ret_val)
			break ;
		i++;
	}
	buff[i] = '\0';
	result = ft_strdup(buff);
	*line = &result[0];
	if (!ret_val)
		return (0);
	return (1);
}
