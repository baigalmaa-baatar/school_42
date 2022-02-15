# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhabou <mkhabou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 13:00:27 by mkhabou           #+#    #+#              #
#    Updated: 2022/02/15 21:02:49 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -I/usr/local/opt/readline/include
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	libft.a

LIBFT_DIR	=	libft

SRCS		=	main.c signals.c dup_envp.c find_path.c my_getenv.c \
				change_env_value.c error_fct.c free_data.c special_putstrs.c \
				prepare_redirections.c prepare_heredoc.c array.c \
				validate_redir.c only_redir.c prepare_input_out.c \
				parse.c parse/parse_process.c parse/resolve_env.c \
				parse/utils_libft.c parse/utils_parse.c	parse/free_t.c \
				parse/eval.c parse/locate_char.c parse/parse_redirection.c \
				parse/parse_utils2.c parse/single_double_unquote.c \
				built_ins/ft_echo_1.c built_ins/ft_echo_2.c \
				built_ins/ft_env.c built_ins/ft_pwd.c built_ins/ft_cd.c \
				built_ins/ft_exit.c built_ins/ft_unset.c \
				built_ins/export/ft_export.c built_ins/export/ft_sort_params.c \
				built_ins/export/print_env.c built_ins/export/utils_export.c \
				execution/find_cmds.c execution/find_built_ins.c \
				execution/exec_cmds.c execution/dup_fds.c \
				execution/exec_pipes_1.c execution/exec_pipes_2.c \
				execution/exec_pipes_3.c \

SRCS_DIR	=	srcs

OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

INC			=	-I inc

.c.o	:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJS}
			make -C ${LIBFT_DIR}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIBFT_DIR} -lft -lreadline -L/usr/local/opt/readline/lib

clean	:
			make fclean -C ${LIBFT_DIR}
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
