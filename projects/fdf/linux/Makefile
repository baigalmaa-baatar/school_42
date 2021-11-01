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

INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS = -Lmlx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

NAME = fdf
SRCS =  srcs/main.c

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
