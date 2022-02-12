/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:24:09 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 16:24:12 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*my_getenv(char *name, char **my_envp)
{
	int	i;

	i = 0;
	if (!my_envp)
		return (NULL);
	while (my_envp[i])
	{
		if (ft_strnstr(my_envp[i], name, ft_strlen(name))
			&& my_envp[i][ft_strlen(name)] == '=')
			return (&(my_envp[i][ft_strlen(name) + 1]));
		else
			i++;
	}
	return (NULL);
}
