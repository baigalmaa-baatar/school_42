/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:29:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 13:01:06 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!str)
		return (0);
	len = ft_strlen(str);
	res = (char *)malloc(sizeof (char) * len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
