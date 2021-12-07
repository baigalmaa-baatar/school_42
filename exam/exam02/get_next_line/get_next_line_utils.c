/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:47:03 by bbaatar           #+#    #+#             */
/*   Updated: 2021/12/07 09:47:04 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(const char *str)
{
    char *result;
    int i;

    result = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
    if (!result)
        return (0);
    i = 0;
    while (str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return(result);
}