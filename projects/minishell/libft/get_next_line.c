/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:33:55 by mkhabou           #+#    #+#             */
/*   Updated: 2021/04/30 15:52:52 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_len(char *txt)
{
	int	i;

	i = 0;
	while (txt && txt[i] != '\n' && txt[i] != '\0')
		i++;
	return (i);
}

char	*ft_read_line(int fd, char *txt)
{
	int		nb;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	nb = read(fd, buffer, BUFFER_SIZE);
	while (nb > 0)
	{
		buffer[nb] = '\0';
		if (!txt)
			txt = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(txt, buffer);
			free(txt);
			txt = tmp;
		}
		if (ft_strchr(txt, '\n'))
			break ;
		nb = read(fd, buffer, BUFFER_SIZE);
	}
	if (!nb && !txt)
		txt = ft_strdup("");
	return (txt);
}

int	get_next_line(int fd, char **line)
{
	static char	*txt;
	char		*tmp;
	int			line_len;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	txt = ft_read_line(fd, txt);
	if (!txt)
		return (-1);
	line_len = ft_line_len(txt);
	*line = ft_substr(txt, 0, line_len);
	if (!txt[line_len])
	{
		free(txt);
		txt = NULL;
		return (0);
	}
	else
	{
		tmp = ft_strdup(&txt[line_len + 1]);
		free(txt);
		txt = tmp;
		return (1);
	}
}
