/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:00:31 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 15:55:20 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, long long *nbr)
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
	if (*nbr > 2147483647 || *nbr < -2147483648)
		return (0);
	return (1);
}
