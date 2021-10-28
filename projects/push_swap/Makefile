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

NAME = push_swap
SRCS =  srcs/push_swap.c\
		srcs/get_numbers.c\
		srcs/operators_a.c\
		srcs/operators_b.c\
		srcs/operators_both.c\
		srcs/b_to_a.c\
		srcs/find_max_or_min.c\
		srcs/sort_4.c\
		srcs/sort_5.c\
		srcs/sort_array.c\
		srcs/sort_big.c\
		srcs/sort_mid.c\
		srcs/sort_small.c\
		srcs/utils_1.c\
		srcs/utils_2.c

INCLUDE = includes
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		make -C libft/
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft/libft.a -o $(NAME)

all:	${NAME}

clean:
		make clean -C libft/
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft/

re:		fclean all
