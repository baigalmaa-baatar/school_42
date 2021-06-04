/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:12:02 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/21 13:12:18 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	while (0 != len && s[len] != (const char)c)
	{
		len--;
	}
	if (s[len] == (const char)c)
	{
		return ((char *)&s[len]);
	}
	return (NULL);
}
