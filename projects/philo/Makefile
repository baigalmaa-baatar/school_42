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

INCLUDE = includes
OBJS = ${SRCS:.c=.o}
CC		= clang
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
LIBS	= -lpthread
.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		make -C libft/
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft/libft.a -o $(NAME) $(LIBS)

all:	${NAME}

clean:
		make clean -C libft/
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft/

re:		fclean all
