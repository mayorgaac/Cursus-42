# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:49:32 by amayorga          #+#    #+#              #
#    Updated: 2024/11/25 21:29:47 by amayorga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

NAME = printf.a
SRC = $(wildcard ./*.c)

OBJ_DIR = obj
OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

${OBJ_DIR}/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = re fclean clean all
