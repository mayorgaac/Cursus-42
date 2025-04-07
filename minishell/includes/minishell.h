/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:56:58 by amayorga          #+#    #+#             */
/*   Updated: 2025/04/07 20:46:28 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL

# define MAX_LINE 1024

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

//LISTA DE COMANDOS
typedef struct s_command {
    char *cmd;                // Comando (ej: "ls")
    char **args;              // Argumentos (ej: ["-l", "/home"])
    char *input_redir;        // Archivo para redirección de entrada (si aplica)
    char *output_redir;       // Archivo para redirección de salida (si aplica)
    struct s_command *next;   // Para lista enlazada de comandos
} t_command;



#endif