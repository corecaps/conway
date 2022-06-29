# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 18:19:05 by jgarcia           #+#    #+#              #
#    Updated: 2022/06/19 20:54:42 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = conway
CURRENT_DIR = $(shell pwd)
CC = gcc
CFLAGS = -Wall -Wextra -g -c

INC = -Iminilibx-linux/
LINK = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

SRC = cell.c main.c graphX.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ) $(CURRENT_DIR)/minilibx/libmlx_Linux.a
	$(CC) $(OBJ) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -o $@

$(CURRENT_DIR)/minilibx/libmlx_Linux.a:
	make -C minilibx-linux

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re