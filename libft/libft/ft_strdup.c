/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:35:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 12:33:47 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*res;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen (str);
	res = (char *)malloc (sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
