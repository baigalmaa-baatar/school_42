/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:59:59 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/12 15:40:47 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	print_env(char **envs)
{
	int	i;
	int	j;
	int	open_quote;

	i = 0;
	while (envs[i])
	{
		open_quote = 0;
		ft_putstr_fd("declare -x ", 1);
		j = 0;
		while (envs[i][j])
		{
			write(1, &envs[i][j], 1);
			if (envs[i][j] == '=' && !open_quote)
			{
				write(1, "\"", 1);
				open_quote = 1;
			}
			j++;
		}
		if (open_quote)
			write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
}

void	sort_print(t_data *data)
{
	char	**envs;

	envs = dup_envp(data->my_envp);
	ft_sort_params(envs, count_elements((void **)data->my_envp));
	print_env(envs);
	ft_free_tab(envs);
}
