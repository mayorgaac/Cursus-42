NAME := minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes/

LIBFT = -L libft -lft

HEADER = minishell.h

#Ir añadiendo los nombres de archivos por carpetas sin el .c
MAIN = minishell

#Ir añadiendo el sufijo .c y el prefijo de la ruta de la carpeta
SRC = $(addsuffix .c, $(addprefix src/main/, $(MAIN))) 

OBJ = $(SRC:c=o)

INCLUDE = includes/minishell.h

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\n\033[0mDone !"


%.o: %.c
	@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: all fclean clean re