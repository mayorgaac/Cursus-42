
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
	@${MAKE} -C ./libft
	@${CC} ${FLAGS} ${OBJ} ./libft/libft.a ./libft/ft_printf/libftprintf.a -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: ${SRC_DIR}/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./libft/ft_printf fclean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

debug:
	@echo "SRC = $(SRC)"
	@echo "OBJ = $(OBJ)"

.PHONY = re fclean clean all