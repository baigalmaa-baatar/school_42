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
	int flag_prec;
	int specifier;
	int negative;
	char *base;
	int base_nbr;
}				t_format;

int	ft_printf(const char *, ...);
int ft_length_nbr(long long nbr);
int ft_length_x(unsigned long long nbr);
int ft_max(int a, int b);
int print_c(struct s_format *format, va_list a_list);
int print_str(struct s_format *format, va_list a_list);
int print_p(struct s_format *format, va_list a_list);
int print_di(struct s_format *format, va_list a_list);
int print_u(struct s_format *format, va_list a_list);
int print_sx(struct s_format *format, va_list a_list);
int print_x(struct s_format *format, va_list a_list);
int print_perc(void);
int detect_width(char *str, struct s_format *format);
int detect_precision(char *str, struct s_format *format);
void prec_point(struct s_format *format);
void x_digits(struct s_format *format, int *max, int *len, char *buff);
int di_digits(struct s_format *format, int *max, int *len, char *buff);
void u_digits(struct s_format *format, int *max, int *len, char *buff);
void x_detect_nbr(unsigned long long *nbr, struct s_format *format, char *buff, int *i);
int	str_detect(const char *str, struct s_format *format, char *buff);
int di_detect_nbr(long *nbr, struct s_format *format, char *buff, int *i);
void putnbr_base(unsigned long long *nbr, struct s_format *format, char *buff, int *i);
void di_putnbr_base(long *nbr, struct s_format *format, char *buff, int *i);

#endif
