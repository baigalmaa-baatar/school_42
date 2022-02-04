/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:38:12 by bbaatar           #+#    #+#             */
/*   Updated: 2022/02/03 20:38:13 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	change_value(t_data *data, char *var, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->my_envp)
	{
		while (data->my_envp[i])
		{
			if (!ft_strnstr(data->my_envp[i], var, ft_strlen(var)))
				i++;
			else
			{
				tmp = ft_mtp_strjoin(var, "=", new_value);
				free(data->my_envp[i]);
				data->my_envp[i] = tmp;
				return ;
			}
		}
	}
}

int	check_var_value(char *s)
{
	int i;

	char *var;
	char *value;

	//TEST=coucou
	i = 0;
	while(s[i])
	{
		if (s[i] == '=' && s[(i + 1)] != '\0')
		{
			var = ft_substr(s, 0, i);
			value = ft_substr(s, i + 1, );
		}
	}

}

void	ft_export(char **complete_cmd, t_data *data)
{
	char	*pwd;

	if (complete_cmd[1])
	{
		if (complete_cmd[2])
		{	
			ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
			g_exit_status = 1;
			// free(pwd);
			return ;
		}
		if (chdir(complete_cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			perror(complete_cmd[1]);
			g_exit_status = 1;
			// free(pwd);
			return ;
		}
	}
	else
	{
		ft_putstr_fd("minishell: export: No directory\n", STDERR_FILENO); // show all envs need to print with "DECLARE -X"
		// g_exit_status = 1;
		// free(pwd);
		return ;
	}
	check_var();
	change_value(data, "TEST", "coucou");
	// free(pwd);
	g_exit_status = 0;
}

int main(void)
{
	char *s= "TEST=coucou";

	int i;
	char *res = NULL;

	res = malloc (100 * sizeof(char));
	res = ft_export(s);
	i = 0;
	while (i < 6)
	{
		printf("param[%d] is : |%s|\n", i, res[i]);
		i++;
	}
	return(0);
}