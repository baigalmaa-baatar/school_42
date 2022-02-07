# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 13:00:27 by mkhabou           #+#    #+#              #
#    Updated: 2021/12/01 13:00:31 by mkhabou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	libft.a

LIBFT_DIR	=	libft

SRCS		=	main.c find_built_ins.c \
				built_ins/ft_echo.c built_ins/ft_env.c built_ins/ft_pwd.c \
				built_ins/ft_cd.c built_ins/ft_exit.c built_ins/ft_unset.c \
				find_cmds.c find_path.c exec_cmds.c exec_pipes.c error_fct.c \
				free_data.c my_getenv.c change_env_value.c \
				parse.c parse/parse_process.c parse/resolve_env.c \
				parse/utils_libft.c parse/utils_parse.c	parse/free_t.c\
				redirection.c
				
SRCS_DIR	=	srcs

OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

INC			=	-I inc

.c.o	:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJS}
			make -C ${LIBFT_DIR}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIBFT_DIR} -lft -lreadline -ltermcap

clean	:
			make fclean -C ${LIBFT_DIR}
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
