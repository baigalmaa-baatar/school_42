/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:30:33 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/04 00:30:35 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str, unsigned long long *nbr)
{
	size_t			i;
	long long		res;
	int				sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + sign *(str[i] - 48);
		else
			return (0);
		i++;
	}
	*nbr = res;
	if (*nbr > 2147483647)
		return (0);
	return (1);
}

// static void	*ft_malloc_free(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i] != 0)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (NULL);
// }

unsigned long long	get_args(char **argv, unsigned long long inputVal[5])
{
	unsigned long long philoNbr;

	ft_atoi(argv[1], &philoNbr);
	ft_atoi(argv[2], &inputVal[1]);
	ft_atoi(argv[3], &inputVal[2]);
	ft_atoi(argv[4], &inputVal[3]);
	return (philoNbr);
}