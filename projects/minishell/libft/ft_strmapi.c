/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:06:59 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/12 18:07:16 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	l;
	int		i;

	if (!s1 || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s1);
	new = malloc(sizeof(char) * (l + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = f(i, s1[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
