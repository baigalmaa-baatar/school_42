NAME = libft.a
SRCS = ft_atoi_changed.c\
		ft_split_changed.c\
		ft_strlen.c\
		ft_putendl_fd.c\
		ft_substr_changed.c\
		ft_strdup.c\
		get_next_line.c
OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -I/includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
