/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:35:39 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/03 10:35:41 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *res;
	unsigned int len;
	unsigned int i;

	len = ft_strlen(str);
	// printf("length %d\n", len);

	if(!(res = (char *)malloc (sizeof(char) * (len + 1))))
		return(NULL);
	i = 0;
	while (len--)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int main()
{
	// char *str;
	// char *tmp = "this is a normal test";
	// int r_size = strlen(tmp);
	// int size;

	// str = ft_strdup(tmp);
	// size = get_last_malloc_size();

	// printf("Std function : %s\nMy function  : %s\n", d1, d2);

	return (0);
}