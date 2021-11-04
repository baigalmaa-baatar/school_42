# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:17:00 by bbaatar           #+#    #+#              #
#    Updated: 2021/11/04 14:17:03 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_S =  server.c
SRC_C =  client.c

INCLUDE = includes
OBJ_S = ${SRC_S:.c=.o}
OBJ_C = ${SRC_C:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

$(SERVER): 
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ_S) $(INCLUDES) libft/libft.a -o $(SERVER)

$(CLIENT): 
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ_C) $(INCLUDES) libft/libft.a -o $(CLIENT)


all:	${SERVER} ${CLIENT}

clean:
		make clean -C libft/
		${RM} ${OBJ_S} ${OBJ_C} 

fclean:	clean
		${RM} ${NAME}
		make fclean -C libft/

re:		fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b