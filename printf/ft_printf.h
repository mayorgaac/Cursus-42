/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:11:38 by amayorga          #+#    #+#             */
/*   Updated: 2024/09/19 12:40:10 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	i_need_lines(char const *format, va_list args, int *bytes);
void	print_type(va_list args, char c, int *bytes);
void	ft_putchar(char c, int *bytes);
void	ft_putstr(char *str, int *bytes);
void	ft_putptr(void *ptr, int *bytes);
void	ft_putnbr(int n, int *bytes);
void	ft_putnbr_unsigned(unsigned int n, int *bytes);
void	ft_puthex_ull(unsigned long long hex, char *hexdigits, int *bytes);
void	ft_puthex_uint(unsigned int hex, char *hexdigits, int *bytes);
//void	ft_escape_char(const char *format, int *bytes);

#endif
