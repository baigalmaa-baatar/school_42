NAME = libftprintf.a
SRCS =  srcs/ft_printf.c \
		# srcs/ft_treatment.c
INCLUDE = include
LIBFT = libft
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		cp libft/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all