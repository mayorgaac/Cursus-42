/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:11:38 by amayorga          #+#    #+#             */
/*   Updated: 2024/03/19 21:54:00 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//ft_printf.c
int ft_printf(char const *format, ...);
char define_type(char const *format);

//write.c
void ft_putchar(char c);
void ft_putstr(char *str);

# endif
