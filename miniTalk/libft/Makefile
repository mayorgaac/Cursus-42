LIB = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

SRC = $(wildcard ./*.c)

OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)
OBJ_DIR = obj

INCLUDE = libft.h

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/printf.a

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(MAKE) -C $(PRINTF_DIR)
	$(LIB) $(NAME) $(OBJ) $(PRINTF_LIB)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

${OBJ_DIR}/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

rebonus: fclean bonus
