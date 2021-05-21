/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:56:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/02/21 15:56:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//DELETE THIS!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <wchar.h>
#include <limits.h>
#include <unistd.h>


size_t	ft_strlen(const char *str);
size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_strdup(const char *str);
char	*ft_strncpy(char * dst, const char * src, size_t len);
char	*ft_substr(const char *str, size_t start_pos, size_t end_pos);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int nbr);

#endif