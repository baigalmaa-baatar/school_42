/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:29:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/05 23:16:10 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_adding_char(unsigned i, char c)
{
	return (c + i);
}

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t i;
	size_t len;
	char *res;

	len = ft_strlen(str);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return(0);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}

int main()
{
	char *b = "override this !";
	char b2[240];
	size_t size = strlen(b);

	size_t i;
	for (i = 0; i < size; i++)
		b2[i] = ft_adding_char(i, b[i]);
	b2[size] = '\0';
	char *ret = ft_strmapi(b, ft_adding_char);
	printf("%s\n", ret);
	return 0;
}
