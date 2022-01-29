#include "../inc/minishell.h"
/*
long long	check_nb(char *str)
{
	int			i;
	int			neg;
	long long	nbr;

	i = 0;
	nbr = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (nbr * neg);
}

int	check(char *str)
{
	long long	nbr;

	if (ft_strlen(str) > 22)
		return (ft_error(NULL, "Error: Argument(s) too long.", 0, -1));
	nbr = ft_atoll(str);
	if (nbr == -1)
		return (ft_error(NULL, "Error: Arguments can only contain digits.", 0, -1));
	if (nbr > 2147483647 || nbr < 1)
		return (ft_error(NULL,
			"Error: Arguments can only be (strictly positive) integers.",
			0, -1));
	return ((int)nbr);
}*/

void	ft_exit(char **complete_cmd)
{
	if (complete_cmd[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		exit_status = 1;
		return ;
	}
	if (complete_cmd[1])
	{
		if (!ft_isdigit(complete_cmd[1][0]))   //temp
		{
			ft_mtp_putendl_fd(STDERR_FILENO, "minishell: exit: ",
				complete_cmd[1], ": numeric argument required");
			exit_status = 2;
			exit(exit_status);
		}
		else
		{
			exit_status = ft_atoi(complete_cmd[1]);
			exit(exit_status);		
		}
	}
	if (!complete_cmd[1])
		exit(exit_status);
}
