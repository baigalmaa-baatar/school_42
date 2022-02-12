/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:26:59 by mkhabou           #+#    #+#             */
/*   Updated: 2022/02/11 16:27:01 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**dup_envp(char *envp[])
{
	int		i;
	char	**my_envp;

	i = 0;
	my_envp = malloc(sizeof(char *) * (ft_tab_len(envp) + 1));
	if (!my_envp)
		error_fct(NULL, "minishell: Malloc failure", 2);
	if (envp)
	{
		while (envp[i])
		{
			my_envp[i] = ft_strdup(envp[i]);
			if (!my_envp[i])
				error_fct(NULL, "minishell: Malloc failure", 2);
			i++;
		}
	}
	my_envp[i] = NULL;
	return (my_envp);
}
