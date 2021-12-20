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

INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS = -Lmlx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

CC = gcc
FLAGS = -Wall -Werror -Wextra -g -O3 
LIBRARIES = -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx_Linux.a
MINILIBX_DIRECTORY = ./mlx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fdf.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = main.c\
				init.c\
				get_numbers.c\
				color.c\
				keyboard.c\
				mouse.c\
				rotate.c\
				plot_line.c\
				transform.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) -g $(LIBRARIES) $(INCLUDES) $(OBJECTS) libft/libft.a -o $(NAME) $(LFLAGS)

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
