/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:07:29 by bbaatar           #+#    #+#             */
/*   Updated: 2022/01/21 15:07:30 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

typedef struct s_process
{
	char	**params;
	//char	*redirect;	/* not sure this moment, if we need it we will use it for redirection. */
}			t_process;

int	str_err(char *err, int i);
int	is_space(char	*str, int i);
char	**split(char *s);
char	*resolve_env(char *s);
int	find_pos(const char *haystack, const char *needle, int len);
char	*strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start_pos, size_t len);
size_t	ft_strlen(const	char *s);
char	*ft_strdup(const char *s1);

#endif