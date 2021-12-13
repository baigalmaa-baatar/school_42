# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 21:33:25 by bbaatar           #+#    #+#              #
#    Updated: 2021/11/01 21:33:27 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fdf.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = main.c\
				get_numbers.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2021/10/28 13:49:18 by bbaatar           #+#    #+#              #
# #    Updated: 2021/10/28 13:49:21 by bbaatar          ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# INC=/usr/include
# INCLIB=$(INC)/../lib
# LFLAGS = -Lmlx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
# INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

# LIBFT = $(LIBFT_DIRECTORY)libft.a
# LIBFT_DIRECTORY = ./libft/

# NAME = fdf
# SRCS =  srcs/main.c\
# 		srcs/get_numbers.c

# OBJS = $(SRCS:.c=.o)
# CC		= gcc
# RM		= rm -f
# CFLAGS = -Wall -Wextra -Werror
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -Ilibft -O3 -c $< -o $@

# $(NAME): $(LIBFT) $(OBJS)
# 	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

# all: $(NAME)

# $(LIBFT):
# 	@$(MAKE) -sC $(LIBFT_DIRECTORY)

# clean:
# 	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
# 	$(RM) $(OBJS)

# fclean:	clean
# 	@rm -f $(LIBFT)
# 	$(RM) $(NAME)

# re:		fclean all