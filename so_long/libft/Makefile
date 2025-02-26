#Directorio para los objetos
OBJ_DIR = ./objects/

#Declaramos los nombres de los archivos objeto
OBJECTS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Indicamos el nombre de nuestro ejecutable
NAME = libft.a

SRC = $(wildcard *.c)

#Indicamos cual va a ser nuetro compilador
CC = cc

#Declaramos nuestros flags
CFLAGS = -Wall -Wextra -Werror

#Declaramos variable para el comando clean
RM = rm -f

#Funcion principal
all: $(NAME)

#Se compila la libreria
$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

#Se compila el bonus
#bonus: all $(OBJECTS_BON)
# 		ar rcs $(NAME) $(OBJECTS_BON)

#Regla para contruir los archivos objeto
$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para crear la carpeta de objetos si no existe
$(OBJ_DIR):
	- mkdir -p $(OBJ_DIR)

#Borrado de objetos
clean:
	$(RM) $(OBJECTS) #$(OBJECTS_BON)

#Borrado de objetos y del ejecutable
fclean: clean
	$(RM) $(NAME)

#Lo borra todo
re: fclean all

#Indicamos que no cree ningun archivo con estos nombres
.PHONY: bonus all clean fclean re
