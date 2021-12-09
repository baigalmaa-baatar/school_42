/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:59:11 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/09 21:06:02 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;

	line = get_next_line (0);
	while (line != NULL)
	{
		write (1, line, strlen(line));
		free (line);
		line = get_next_line(0);
	}
	return (0);
}
