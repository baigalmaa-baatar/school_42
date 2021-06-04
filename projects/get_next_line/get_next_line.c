/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:26:33 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/02 14:25:03 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int i;
	char *c;
	int BUFFER_SIZE = 10;

	c = (char *)malloc(100 * sizeof(char));
	if (fd < 0)
		return (-1);
	i = read(fd, c, BUFFER_SIZE);
	c[i] = '\0';
	i = 0;
	while(c[i] != '\0')
	{
		if(c[i] == '\n')
			break;
		i++;
	}
	*line = &c[i];

	return (1);
}
