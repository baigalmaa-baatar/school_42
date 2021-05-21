/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:53:52 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/05 10:23:40 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char *res;
	size_t i;
	size_t k;
	unsigned int len_str;

	if (!str || !set)
		return(0);
	len_str = ft_strlen(str);
	i = 0;

	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '\0')
		return("");
	len_str--;
	while (str[len_str] == ' ' || str[len_str] == '\t' || str[len_str] == '\n' || str[len_str] == '\v' || str[len_str] == '\f' || str[len_str] == '\r')
		len_str--;
	if (!(res = (char *)malloc(sizeof(char) * (len_str - i + 2))))
		return (0);
	k = 0;
	while(len_str >= i)
	{
		res[k] = str[i];
		i++;
		k++;
	}
	res[k] = '\0';
	return (res);
}