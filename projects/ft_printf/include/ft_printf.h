/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:08:44 by bbaatar           #+#    #+#             */
/*   Updated: 2021/09/18 23:25:28 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		print_val(const char *str, va_list a_list);
int		print_c(va_list a_list);
int		print_di(va_list a_list);
int		print_p(va_list a_list);
int		print_perc(void);
int		print_str(va_list a_list);
int		print_sx(va_list a_list);
int		print_u(va_list a_list);
int		print_x(va_list a_list);
int		putnbr_base_without_zero(unsigned long long nbr, unsigned int base_nbr,
			char *base);
int		putnbr_base(unsigned long long nbr, unsigned int base_nbr, char *base);

#endif
