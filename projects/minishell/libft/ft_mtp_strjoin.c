/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtp_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:08:01 by mkhabou           #+#    #+#             */
/*   Updated: 2021/07/21 19:08:03 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mtp_strjoin(char *s1, char *s2, char *s3)
{
	char	*new;
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		perror("ft_mtp_strjoin: Malloc error");
		exit(3);
	}
	new = ft_strjoin(tmp, s3);
	free(tmp);
	if (!new)
	{
		perror("ft_mtp_strjoin: Malloc error");
		exit(3);
	}
	return (new);
}
