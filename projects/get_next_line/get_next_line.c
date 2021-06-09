/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:26:33 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/08 12:45:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int get_next_char(int fd, char *ch)
{
	static char	buff[BUFFER_SIZE];
	static int	i = 0;
	static int	fd_res = 0;

	if (i < fd_res)
	{	
		*ch = buff[i++];
		return (1);
	}
	else
	{
		fd_res = read(fd, buff, BUFFER_SIZE);
		if (fd_res <= 0)
			return (fd_res);
		i = 0;
		*ch = buff[i++];
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	int		i;
	char	*res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	res = (char *)malloc(BUFFER_SIZE + 1);
	if (!res)
		return (0);
	i = 0;
	while (1)
	{
		if (get_next_char(fd, &res[i]) < 0)
		{
			free(res);
			return (-1);
		}
		if (!res[i])
			return (0);
		if (res[i] == '\n')
			break ;
		i++;
	}
	res[i] = '\0';
	*line = &res[0];
	return (1);
}

// int   main()
// {
//   char  *line;
//   int   fd3;

//   fd3 = open("file2", O_RDONLY);

//   get_next_line(fd3, &line);
//   printf("current buff is : %s\n", line);
  
//   get_next_line(fd3, &line);
//   printf("current buff is : %s\n", line);
  
//   get_next_line(fd3, &line);
//   printf("current buff is : %s\n", line);

//   get_next_line(fd3, &line);
//   printf("current buff is : %s\n", line);

//   get_next_line(fd3, &line);
//   printf("current buff is : %s\n", line);

//   return (0);
// }
