/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:08:44 by bbaatar           #+#    #+#             */
/*   Updated: 2021/06/16 11:10:32 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_format
{
	// flags
	int minus;
	int plus;
	int space;
	int	zero;
	int apostrophe;
	int	hash;
	//width
	int width;
	//precision
	int precision;
	//length
	int length;
}				t_format;

int	ft_printf(const char *, ...);

#endif