/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:29:41 by bbaatar           #+#    #+#             */
/*   Updated: 2021/05/05 17:29:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_get_len(int nbr)
{
    size_t len;
	long long nbr_long;

    len = 1; 
	nbr_long = nbr;
    if (nbr_long < 0)
    {
        nbr_long = -nbr_long;
        len++;
    }
    while(nbr_long >= 10)
    {
        nbr_long /= 10;
        len++;
    }
    return(len);
}

char	*ft_itoa(int nbr)
{
    char *result;
    size_t len;
	long long nbr_long;

    len = ft_get_len(nbr);
    if(!(result = (char *)malloc((len + 1)* sizeof(char))))
		return(0);
    result[len--] = '\0';
	nbr_long = nbr;
    if(!nbr)
        result[0] = '0';
    else if (nbr_long < 0)
    {
        nbr_long = -nbr_long;
        result[0] = '-';
    }
    while(nbr_long)
    {
        result[len] = nbr_long % 10 + '0';
        nbr_long /= 10;
        len--;
    }
    return (result);
}
// int main()
// {
//     char *str;

//     str = ft_itoa(1046911295);
//     printf("%s\n", str);
//     free(str);
//     return 0;
// }