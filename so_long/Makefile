NAME = so_long

RM = rm -rf

CC = cc
FLAGS = -Wall -Werror -Wextra -g -Iminilibx

SRC_DIR = src
SRC = $(wildcard ${SRC_DIR}/*.c)

OBG_DIR = obj
OBJ = $(SRC:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

INCLUDE = so_long.h

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -Lminilibx -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

PRINTF_DIR = libft/printf
PRINTF_LIB = ${PRINTF_DIR}/printf.a
#INCLUIR ft_printf
#INCLUIR get_next_line

all:$(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME):$(OBJ)
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${PRINTF_DIR}
	@${CC} ${FLAGS} ${OBJ} ${LIBFT_LIB} ${PRINTF_LIB} ${MLX_FLAGS} -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: ${SRC_DIR}/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ_DIR)
	@${MAKE} -C ${LIBFT_DIR} clean
	@${MAKE} -C ${PRINTF_DIR} clean
	@make -C $(MLX_DIR) clean

fclean: clean
		@$(RM) $(NAME)
		@${MAKE} -C ${LIBFT_DIR} fclean
		@${MAKE} -C ${PRINTF_DIR} fclean
		@make -C $(MLX_DIR) clean

re: fclean all

.PHONY = re fclean clean all
