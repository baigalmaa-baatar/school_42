# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 13:49:18 by bbaatar           #+#    #+#              #
#    Updated: 2022/01/09 18:49:14 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS =  srcs/create_thrds.c\
		srcs/check_ate_enough.c\
		srcs/is_stop_running.c\
		srcs/eat.c\
		srcs/utils.c\
		srcs/join_thrds.c\
		srcs/take_release_forks_running.c\
		srcs/display_stat.c\
		srcs/main.c

INCLUDE = includes
OBJS = ${SRCS:.c=.o}
CC		= clang
RM		= rm -f
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -g
LIBS	= -lpthread
.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBS)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
