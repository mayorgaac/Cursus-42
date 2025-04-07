/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:06:35 by amayorga          #+#    #+#             */
/*   Updated: 2025/04/07 20:45:15 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void execute_command(char *cmd/*, char **env*/) {
    char *args[100];
    char *token;
    int i = 0;

    // Dividir el comando en tokens
    token = strtok(cmd, " \n");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    // Crear un nuevo proceso para ejecutar el comando
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);  // Ejecutar el comando
        perror("Error");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);  // Esperar a que termine el proceso hijo
    } else {
        perror("Fork failed");
    }
}

int main(/*int argc, char **argv, char **env*/)
{
    char line[MAX_LINE];
    
    while (1)
    {
        printf("minishell> ");
        
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;  // Salir si hay error o EOF
        }
        // Salir si el usuario escribe "exit"
        if (strncmp(line, "exit", 4) == 0) {
            break;
        }
        // Ejecutar el comando
        execute_command(line/*, env*/);
    }

   return 0;
}
