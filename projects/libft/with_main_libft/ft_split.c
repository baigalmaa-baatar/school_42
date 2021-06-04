/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:27:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/05 17:27:45 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_wlen(const char *str, int len)
{
	char *res;
	unsigned int i;

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

int ft_count_strs(char *str, char c)
{
	int count;
	int i;
	int len;

	count = 0;
	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char **ft_split(char *str, char c)
{
	char **output;
	int i;
	int j;
	int curr_start;
	int len;

	if(!str || !c)
		return(0);
	if (!(output = malloc((ft_count_strs(str, c) + 1) * sizeof(char *))))
		return(0);
	len = ft_strlen(str);
	curr_start = 0;
	i = 0;
	j = 0;
	while (i <= len)
	{
		if (str[i] == c || str[i] == '\0')
		{
			if (curr_start < i)
				output[j++] = ft_strdup_wlen(&str[curr_start], i - curr_start);
			curr_start = i + 1;
		}
		i++;
	}
	output[j] = 0;
	return (output);
}

int main()
{
	char *s = "  lol";
	char **result = ft_split(s, ' ');
	int i = 0;
	while (i < 1)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return(0);
}
