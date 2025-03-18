#Mandatory
NAME_CLIENT = client
NAME_SERVER = server

DIR_CLIENT = src/client
SRC_CLIENT = $(wildcard ${DIR_CLIENT}/*.c)
OBG_DIR_CLIENT = obj/client
OBJ_CLIENT = $(SRC_CLIENT:${DIR_CLIENT}/%.c=${OBG_DIR_CLIENT}/%.o)

DIR_SERVER = src/server
SRC_SERVER = $(wildcard ${DIR_SERVER}/*.c)
OBG_DIR_SERVER = obj/server
OBJ_SERVER = $(SRC_SERVER:${DIR_SERVER}/%.c=${OBG_DIR_SERVER}/%.o)

INCLUDE = minitalk.h

#Bonus
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

DIR_CLIENT_BONUS = src_bonus/client
SRC_CLIENT_BONUS = $(wildcard ${DIR_CLIENT_BONUS}/*.c)
OBG_DIR_CLIENT_BONUS = obj_bonus/client
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:${DIR_CLIENT_BONUS}/%.c=${OBG_DIR_CLIENT_BONUS}/%.o)

DIR_SERVER_BONUS = src_bonus/server
SRC_SERVER_BONUS = $(wildcard ${DIR_SERVER_BONUS}/*.c)
OBG_DIR_SERVER_BONUS = obj_bonus/server
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:${DIR_SERVER_BONUS}/%.c=${OBG_DIR_SERVER_BONUS}/%.o)

INCLUDE_BONUS = minitalk_bonus.h

CC = cc
FLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

PRINTF_DIR = libft/printf
PRINTF_LIB = ${PRINTF_DIR}/printf.a


all: ${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT} : ${OBJ_CLIENT}
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${PRINTF_DIR}
	@${CC} ${FLAGS} ${OBJ_CLIENT} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME_CLIENT}

${NAME_SERVER} : ${OBJ_SERVER}
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${PRINTF_DIR}
	@${CC} ${FLAGS} ${OBJ_SERVER} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME_SERVER}


$(OBG_DIR_CLIENT)/%.o: ${DIR_CLIENT}/%.c | $(OBG_DIR_CLIENT)
	$(CC) $(FLAGS) -c -o $@ $<

$(OBG_DIR_SERVER)/%.o: ${DIR_SERVER}/%.c | $(OBG_DIR_SERVER)
	$(CC) $(FLAGS) -c -o $@ $<


$(OBG_DIR_CLIENT):
	mkdir -p $(OBG_DIR_CLIENT)

$(OBG_DIR_SERVER):
	mkdir -p $(OBG_DIR_SERVER)

bonus: ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

${NAME_CLIENT_BONUS} : ${OBJ_CLIENT_BONUS}
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${PRINTF_DIR}
	@${CC} ${FLAGS} ${OBJ_CLIENT_BONUS} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME_CLIENT_BONUS}

${NAME_SERVER_BONUS} : ${OBJ_SERVER_BONUS}
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${PRINTF_DIR}
	@${CC} ${FLAGS} ${OBJ_SERVER_BONUS} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME_SERVER_BONUS}

$(OBG_DIR_CLIENT_BONUS)/%.o: ${DIR_CLIENT_BONUS}/%.c | $(OBG_DIR_CLIENT_BONUS)
	$(CC) $(FLAGS) -c -o $@ $<

$(OBG_DIR_SERVER_BONUS)/%.o: ${DIR_SERVER_BONUS}/%.c | $(OBG_DIR_SERVER_BONUS)
	$(CC) $(FLAGS) -c -o $@ $<

$(OBG_DIR_CLIENT_BONUS):
	mkdir -p $(OBG_DIR_CLIENT_BONUS)

$(OBG_DIR_SERVER_BONUS):
	mkdir -p $(OBG_DIR_SERVER_BONUS)

clean:
	make clean -C ft_printf
	make clean -C libft
	@printf "\e[38;5;46m💥 .o files deleted\e[0m\n"

fclean:
	make fclean -C ${PRINTF_DIR}
	make fclean -C ${LIBFT_DIR}
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	rm -f $(NAMES_B) $(NAMEC_B)
	@printf "\e[38;5;226m🧹 Binaries and .o deleted\e[0m\n"

re:	fclean all

.PHONY: all fclean clean re bonus