/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:31 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/06 13:27:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_var(int seen[255])
{
	int	i;

	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		i++;
	}
}

void	compare_chars(char *argv[], int order, int seen[])
{
	int	i;

	i = 0;
	while (argv[order][i])
	{
		if (seen[(unsigned char)argv[order][i]] == 0)
		{
			write(1, &argv[order][i], 1);
			seen[(unsigned char)argv[order][i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	seen[255];

	if (argc == 3)
	{
		init_var(seen);
		compare_chars(argv, 1, seen);
		compare_chars(argv, 2, seen);
	}
	write(1, "\n", 1);
}
