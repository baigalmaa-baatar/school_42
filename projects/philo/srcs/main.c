/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:57:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/28 20:57:38 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

#define PHILO_NBR   2
#define ERR_CRT "Failed to create thread"
#define ERR_JOIN "Failed to join thread"
#define ERR_DET "Failed to detach thread"

size_t	ft_strlen(const	char	*str)
{
	size_t	len;

	len = 0;
	if (str[0] == '\0')
		return (len);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int str_err(char *str, int ret)
{
    write(1, str, ft_strlen(str));
    return (ret);
}

void    *routine(void   *arg)
{
    printf("Thread has started\n");

    return (arg);
}

int main(void)
{
    int i;
    pthread_t   p[PHILO_NBR];

    i = 0;
    while(i < 2)
    {
        if (pthread_create(&p[i], NULL, &routine, NULL) != 0)
            str_err(ERR_CRT, 1);
        i++;
    }
    i = 0;
    while(i < 2)
    {
        if (pthread_join(p[i], NULL) != 0)
            str_err(ERR_JOIN, 1);
        i++;
    }
    i = 0;
    while(i < 2)
    {
        if (pthread_detach(p[i]) != 0)
            str_err(ERR_DET, 1);
        i++;
    }
    
    return (0);

}

