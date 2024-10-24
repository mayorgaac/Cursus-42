# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:49:32 by amayorga          #+#    #+#              #
#    Updated: 2024/06/18 18:59:07 by amayorga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
SRC = ft_printf.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_puthex.c

INCLUDE = ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = re fclean clean all