NAME := minishell

RM = rm -rf

CC = gcc
FLAGS = -Wall -Werror -Wextra -g 

SRC_DIR = src
SRC =  $(wildcard ${SRC_DIR}/*.c)

OBJ_DIR = obj
OBJ = $(SRC:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

INCLUDE = includes/minishell.h

#Incluir LIBFT
LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

all: $(NAME)

$(NAME): ${OBJ}
	@${MAKE} -C ${LIBFT_DIR}
	@${CC} ${FLAGS} ${OBJ} ${LIBFT_LIB} -o ${NAME}

$(OBG_DIR)/%.o: ${SRC_DIR}/%.c | $(OBG_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	@printf "\e[38;5;46m💥 .o files deleted\e[0m\n"

fclean: clean
	rm -f $(NAME)
	@printf "\e[38;5;226m🧹 Binaries and .o deleted\e[0m\n"

re:	fclean all

.PHONY: all fclean clean re