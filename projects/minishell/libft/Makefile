# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 19:58:32 by mkhabou           #+#    #+#              #
#    Updated: 2021/02/15 20:33:02 by mkhabou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			= 	clang

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

SRCS		=	ft_atoi.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
				ft_memmove.c ft_memccpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_strlen.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
				ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				get_next_line.c \
				ft_convert_from_decimal.c ft_strfill.c \
				ft_free_tab.c ft_mtp_free.c ft_mtp_putendl_fd.c ft_mtp_strjoin.c \
				ft_atoll.c ft_convert_base.c ft_tab_len.c ft_mtp_free_tabs.c \
				ft_tab_join.c ft_tab_str_join.c


BONUS		=	ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

OBJS		=	$(SRCS:.c=.o)

OBJSBONUS	=	$(BONUS:.c=.o)

$(NAME)		:	$(OBJS)
				ar rc $(NAME) $(OBJS)

all			:	$(NAME)

bonus		:	$(OBJS) $(OBJSBONUS)
				ar rc $(NAME) $(OBJS) $(OBJSBONUS)

clean		:
				$(RM) $(OBJS) $(OBJSBONUS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean $(NAME)

.PHONY		:	all bonus clean fclean re