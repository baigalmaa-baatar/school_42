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

int	check_char(char **envs, int *open_quote, int i)
{
	int	j;

	j = 0;
	while (envs[i][j])
	{
		if (!special_putchar(envs[i][j], 1))
			return (0);
		if (envs[i][j] == '=' && !*open_quote)
		{
			if (!special_putstr("\"", 1))
				return (0);
			*open_quote = 1;
		}
		j++;
	}
	return (1);
}

int	print_env(char **envs)
{
	int	i;
	int	open_quote;

	i = 0;
	while (envs[i])
	{
		open_quote = 0;
		if (!special_putstr("declare -x ", 1))
			return (0);
		if (!check_char(envs, &open_quote, i))
			return (0);
		if (open_quote)
		{
			if (!special_putstr("\"", 1))
				return (0);
		}
		if (!special_putstr("\n", 1))
			return (0);
		i++;
	}
	return (1);
}

void	sort_print(t_data *data)
{
	char	**envs;

	envs = dup_envp(data->my_envp);
	ft_sort_params(envs, count_elements((void **)data->my_envp));
	if (!print_env(envs))
	{
		perror("minishell: export: write error");
		g_exit_status = 1;
		ft_free_tab(envs);
		return ;
	}
	ft_free_tab(envs);
}
