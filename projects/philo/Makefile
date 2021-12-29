# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 13:49:18 by bbaatar           #+#    #+#              #
#    Updated: 2021/10/28 13:49:21 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS =  srcs/main.c\
		srcs/utils.c

INCLUDE = includes
OBJS = ${SRCS:.c=.o}
CC		= clang
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
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