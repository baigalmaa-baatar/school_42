NAME = libft.a
SRCS = ft_atoi.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_itoa.c\
		ft_strlen.c\
		ft_strdup.c
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -Ilibft.h -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all