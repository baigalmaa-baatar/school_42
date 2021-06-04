/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:23 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/06 17:01:55 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;
	i = 0;
	if (!s || fd < 0)
		return;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}