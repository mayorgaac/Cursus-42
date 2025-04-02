/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:51:34 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:54:05 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# include <unistd.h>
//# include <stdlib.h>
# include "../libft.h"

# define BUFFER_SIZE 1024

char	*ft_free(char *res, char *buffer);
char	*ft_next(char *buffer);
char	*read_line(char *res);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

//int		ft_strlen(const char *str);
//int		ft_strchr(char *buffer, char caracter);
//char	*ft_strjoin(char const *s1, char const *s2);
//void	*ft_memset(void *b, int c, size_t len);
//void	*ft_calloc(size_t count, size_t size);

#endif
