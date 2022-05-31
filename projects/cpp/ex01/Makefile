NAME = phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp

OBJS = ${SRCS:.c=.o}
CC		= clang++
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
.c.o:
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
		make clean
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all