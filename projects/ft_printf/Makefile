NAME = libftprintf.a
SRCS =  srcs/print_str.c\
		srcs/print_sx.c\
		srcs/print_c.c\
		srcs/print_u.c\
		srcs/print_di.c\
		srcs/print_x.c\
		srcs/ft_printf.c\
		srcs/print_p.c\
		srcs/putnbr_base.c\
		srcs/print_perc.c\

INCLUDE = include
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
