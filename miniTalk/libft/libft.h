/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:06:53 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/04 20:58:15 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef STDLIB_H_INCLUDED
#  define STDLIB_H_INCLUDED
#  include <stdlib.h>
# endif

# ifndef UNISTD_H_INCLUDED
#  define UNISTD_H_INCLUDED
#  include <unistd.h>
# endif

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_strlen(const char *s);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_atoi(const char *str);

long				ft_atol(const char *str);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

void				*ft_calloc(int count, int size);

char				*ft_strdup(const char *src);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

char				*ft_itoa(int n);

char				**ft_split(char const *s, char c);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstclear(t_list **lst, void (*del)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

size_t				ft_count_words(char const *s, char c);

#endif