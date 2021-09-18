/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:32:30 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/18 22:00:53 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_str(struct s_format *format, va_list a_list)
{
	char		buff[100];
	const char	*str;
	const char	*str_buff;
	int			max;

	str_buff = va_arg(a_list, const char *);
	if (!str_buff)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str_buff);
	memset (buff, ' ', 100 * sizeof(char));
	prec_point (format);
	max = str_detect(str, format, buff);
	free((char *)str);
	if (!str)
		return (0);
	return (max);
}
