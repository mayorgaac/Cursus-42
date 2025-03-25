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

OBJ_DIR = obj

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

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	@printf "\e[38;5;46m💥 .o files deleted\e[0m\n"

fclean:
	make clean -C $(PRINTF_DIR)
	make fclean -C ${LIBFT_DIR}
	rm -rf $(OBJ_DIR)
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@printf "\e[38;5;226m🧹 Binaries and .o deleted\e[0m\n"

re:	fclean all

.PHONY: all fclean clean re bonus
