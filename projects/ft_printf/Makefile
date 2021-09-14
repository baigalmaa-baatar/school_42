NAME = libftprintf.a
SRCS =  srcs/ft_printf.c\
		srcs/ft_tools.c\
		srcs/print_c.c\
		srcs/print_p.c\
		srcs/print_str.c\
		srcs/print_u.c\
		srcs/detect_wid_prec.c\
		srcs/print_x.c\
		srcs/print_di.c\
		srcs/print_perc.c\
		srcs/print_sx.c
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