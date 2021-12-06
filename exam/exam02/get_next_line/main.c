/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:45 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/06 14:21:47 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line;

	while (get_next_line(&line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
