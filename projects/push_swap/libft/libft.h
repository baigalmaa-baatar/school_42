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

size_t	ft_strlen(const	char	*str);
char	*ft_substr(const char *s, unsigned int start_pos, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, long long *nbr);

#endif
