# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:17:00 by bbaatar           #+#    #+#              #
#    Updated: 2021/11/29 16:49:39 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
SERVER = server
CLIENT = client

SRC_S =  server.c
SRC_C =  client.c

INCLUDE = includes
OBJ_S = server
OBJ_C = client
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror -g

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): 
		make -C libft/
		$(CC) $(CFLAGS) $(SRC_S) $(INCLUDES) libft/libft.a -o $(SERVER)

$(CLIENT): 
		$(CC) $(CFLAGS) $(SRC_C) $(INCLUDES) libft/libft.a -o $(CLIENT)

all:	$(CLIENT) $(SERVER)

clean:
		make clean -C libft/
		$(RM) $(OBJ_S) $(OBJ_C) 

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
