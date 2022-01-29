/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:00:44 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/12 13:02:08 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	d;

	d = c;
	l = 0;
	while (s[l])
		l++;
	if (d == s[l])
		return ((char *)&s[l]);
	while (l >= 0)
	{
		if (s[l] == d)
			return ((char *)&s[l]);
		l--;
	}
	return (0);
}
