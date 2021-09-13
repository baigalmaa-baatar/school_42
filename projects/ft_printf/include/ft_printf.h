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
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_format
{
	int width;
	int width_digit;
	int precision;
	int precision_digit;
	int specifier;
}				t_format;

int	ft_printf(const char *, ...);
int ft_length_nbr(long long nbr);
int ft_length_X(unsigned int nbr);
int ft_max(int a, int b);
int print_c(struct s_format *format, va_list a_list);
int print_str(struct s_format *format, va_list a_list);
int print_p(struct s_format *format, va_list a_list);
int print_di(struct s_format *format, va_list a_list);
int print_u(struct s_format *format, va_list a_list);
int print_sx(struct s_format *format, va_list a_list);
int print_X(struct s_format *format, va_list a_list);
int print_perc(void);
int detect_width(char *str, struct s_format *format);
int detect_precision(char *str, struct s_format *format);

#endif
