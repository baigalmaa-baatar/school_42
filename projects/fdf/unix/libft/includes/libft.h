/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:56:37 by bbaatar           #+#    #+#             */
/*   Updated: 2021/10/26 15:51:43 by bbaatar          ###   ########.fr       */
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
# include "../get_next_line.h"

size_t	ft_strlen(const	char	*str);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr_changed(const char *s, unsigned int start_pos, size_t len);
char	**ft_split_changed(char const *s, char c);
int		ft_atoi_changed(const char *str, long long *nbr);

#endif
