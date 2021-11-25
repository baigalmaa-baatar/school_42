/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:56:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/11/25 11:57:49 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<string.h>
# include	<stdlib.h>
# include	<ctype.h>
# include	<wchar.h>
# include	<limits.h>
# include	<unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nbr, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
