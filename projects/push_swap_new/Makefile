NAME = push_swap.a
SRCS =  srcs/push_swap.c\
		srcs/get_numbers.c

INCLUDE = include
LIBFT = libft
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C libft/
		cp libft/libft.a ./$(NAME)
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		make clean -C libft/
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft/

re:		fclean all