/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:53:52 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/03 10:53:58 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, size_t start_pos, size_t size)
{
	char *res;
	size_t i;

	if (!str || !size)
		return(0);
	if (start_pos >= ft_strlen(str))
		{
			res = (char *)malloc(sizeof(char));
			res[0] = '\0';
			return(res);
		}
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (size--)
	{
		res[i] = str[start_pos];
		start_pos++;
		i++;
	}
	res[i] = '\0';
	return (res);
}