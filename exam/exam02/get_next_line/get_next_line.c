/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:47:03 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/07 09:47:04 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int get_next_char (int fd, char *c)
{
    static char buff[BUFFER_SIZE];
    static int i = 0;
    static int fd_result = 0;

    if (i < fd_result)
    {
        *c = buff[i++];
        return (1);
    }
    fd_result = read (fd, buff, BUFFER_SIZE);
    if (fd_result <= 0)
        return (fd_result);
    i = 0;
    *c = buff[i++];
    return (1);
}

char    *get_next_line (int fd)
{
    int i;
    char *result;
    int ret_val;
    static char tmp_buff[32000];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    i = 0;
    while (1)
    {
        ret_val = get_next_char(fd, &tmp_buff[i]);
        if (ret_val < 0)
            return (0);
        if (tmp_buff[i] == '\n' || !ret_val)
            break ;
        i++;
    }
	if (ret_val > 0)
	{
    	tmp_buff[i] = '\n';
    	i++;
	}
    tmp_buff[i] = '\0';
	if (ft_strlen(tmp_buff) == 0)
		return (0);
    result = ft_strdup(tmp_buff);
    return (&result[0]);
}