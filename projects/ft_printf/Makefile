NAME = libftprintf.a
SRCS =  srcs/detect_wid_prec.c\
		srcs/print_str.c\
		srcs/u_digits.c\
		srcs/di_detect_nbr.c\
		srcs/prec_point.c\
		srcs/print_sx.c\
		srcs/x_detect_nbr.c\
		srcs/di_digits.c\
		srcs/print_c.c\
		srcs/print_u.c\
		srcs/x_digits.c\
		srcs/di_putnbr_base.c\
		srcs/print_di.c\
		srcs/print_x.c\
		srcs/ft_printf.c\
		srcs/print_p.c\
		srcs/putnbr_base.c\
		srcs/ft_tools.c\
		srcs/print_perc.c\
		srcs/str_detect.c

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