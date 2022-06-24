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

CC = gcc
CFLAGS = -Wall -Wextra -g -c

INC = -I/usr/local/include
LINK = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz

SRC = cell.c main.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
