/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:08:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/06 12:35:10 by bbaatar          ###   ########.fr       */
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

void	compare_chars(char *argv[], int seen[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j] &&
					seen[(unsigned char)argv[1][i]] == 0)
			{
				write(1, &argv[1][i], 1);
				seen[(unsigned char)argv[1][i]] = 1;
				break ;
			}
			j++;
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
		compare_chars(argv, seen);
	}
	write(1, "\n", 1);
}
