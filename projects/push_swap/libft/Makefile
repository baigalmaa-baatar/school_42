NAME = libft.a
SRCS = ft_atoi.c
BONUS =  
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -Ilibft.h -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME}
bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re:		fclean all