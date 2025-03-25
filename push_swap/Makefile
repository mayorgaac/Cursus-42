# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 20:06:56 by amayorga          #+#    #+#              #
#    Updated: 2025/03/12 21:17:37 by amayorga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

RM = rm -rf

CC = gcc
FLAGS = -Wall -Werror -Wextra -g 

SRC_DIR = src
SRC =  $(wildcard ${SRC_DIR}/*.c)

OBJ_DIR = obj
OBJ = $(SRC:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

INCLUDE = push_swap.h

all: $(NAME)

$(NAME) : ${OBJ} $(INCLUDE)
	@${MAKE} -C ./Libft
	@${CC} ${OBJ} ./Libft/libft.a ./Libft/ft_printf/libftprintf.a -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: ${SRC_DIR}/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@${MAKE} -C ./Libft fclean
	@${MAKE} -C ./Libft/ft_printf fclean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean allpwd

debug:
	@echo "SRC = $(SRC)"
	@echo "OBJ = $(OBJ)"

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
				
test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					valgrind --leak-check=full --track-origins=yes ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY = re fclean clean all