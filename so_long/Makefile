NAME = so_long

RM = rm -rf

CC = cc
FLAGS = -Wall -Werror -Wextra -Iminilibx

SRC_DIR = src
SRC = $(wildcard ${SRC_DIR}/*.c)

OBG_DIR = obj
OBJ = $(SRC:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

INCLUDE = so_long.h

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -Lminilibx -lmlx -lXext -lX11 -lm -lbsd

#INCLUIR libft
#INCLUIR ft_printf
#INCLUIR get_next_line

all:$(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME):$(OBJ)
	@${CC} ${FLAGS} ${OBJ} ${MLX_FLAGS} -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: ${SRC_DIR}/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
		@$(RM) $(NAME)
		@make -C $(MLX_DIR) clean

re: fclean all

.PHONY = re fclean clean all
