#include "../inc/minishell.h"

int	check_nb(char *str, long long *nb)
{
	int			i;
	int			neg;
	long long	nbr;
	long long	check;

	i = 0;
	nbr = 0;
	neg = 1;
	check = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
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
			return (0);
		nbr = (nbr * 10) + str[i] - 48;
		printf("AV nbr = %lld et check = %lld, diff = %lld\n", nbr, check, llabs(nbr - check));
		if (llabs(nbr - check) > nbr)
			return (0);
		check = nbr;
		i++;
	}
	if (!nbr && check)
		return (0);
	*nb = nbr * neg;
	return (1);
}

void	ft_exit(char **complete_cmd)
{
	int			res;
	long long	nb;

	if (complete_cmd[1])
	{
		if (complete_cmd[2])
		{
			ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
			exit_status = 1;
			return ;
		}
		res = check_nb(complete_cmd[1], &nb);
		if (!res)
		{
			ft_mtp_putendl_fd(STDERR_FILENO, "minishell: exit: ",
				complete_cmd[1], ": numeric argument required");
			exit_status = 2;
			exit(exit_status);
		}
		else
		{
			exit_status = nb;
			exit(exit_status);		
		}
	}
	exit(exit_status);
}
