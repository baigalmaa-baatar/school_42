/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:55:33 by mkhabou           #+#    #+#             */
/*   Updated: 2021/02/15 20:36:05 by mkhabou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// Get_next_line
int					get_next_line(int fd, char **line);

// Ft_printf
char				*ft_strfill(char c, int size);
char				*ft_convert_from_decimal(long long number, char *base_to,
						int base_len);

// Pipex
void				ft_free_tab(char **tabs);
void				ft_mtp_free(char *s1, char *s2, char *s3, char *s4);
void				ft_mtp_putendl_fd(int fd, char *s1, char *s2, char *s3);
char				*ft_mtp_strjoin(char *s1, char *s2, char *s3);

// Push_swap
long long			ft_atoll(const char *str);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_tab_len(char **tab);
void				ft_mtp_free_tabs(char **tabs1, char **tabs2, char **tabs3,
						char **tabs4);
char				**ft_tab_join(char **tab1, char **tab2);
char				**ft_tab_str_join(char **tab, char *str);

//	Minishell
int					ft_isspace(int c);
int					ft_nb_occurences(char c, char *s);
void				ft_mtp_putstr_fd(char *s1, char *s2, char *s3, int fd);

#endif
