#include "../inc/minishell.h"

int	ft_strfind(char c, char *s) //searches for another character than c, in string s
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	option_n(char **complete_cmd, int *index)
{
	int	i;
	int	newline;
	
	i = 1;
	newline = 1;
	while (complete_cmd[i])
	{
		*index = i;
		if (ft_strnstr(complete_cmd[i], "-n", 2))
		{
			newline = 0;
			if (!ft_strfind('n', &complete_cmd[i][1]))
			{
				if (i == 1)
						newline = 1;
					return (newline);
			}
		}
		else
			return (newline);
		i++;
	}
	return (newline);
}

void	ft_echo(char **complete_cmd)
{
	int	i;
	int	newline;

	if (complete_cmd[1])
	{		
		newline = option_n(complete_cmd, &i); //looks for option -n
		if (complete_cmd[1][0] == '$' && complete_cmd[1][1] == '?') //temp, testing "$?" cmd (exit status)
		{
			char *tmp = ft_itoa(exit_status);
			free(complete_cmd[1]);
			complete_cmd[1] = tmp;
		}
		while (complete_cmd[i])
		{
			if (newline && !complete_cmd[i + 1])
				printf("%s\n", complete_cmd[i]);
			else if (!newline && !complete_cmd[i + 1])
				printf("%s", complete_cmd[i]);
			else
				printf("%s ", complete_cmd[i]);
			i++;
		}
	}
	exit_status = 0;
}