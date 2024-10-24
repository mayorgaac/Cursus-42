/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:58:18 by amayorga          #+#    #+#             */
/*   Updated: 2024/06/18 19:00:55 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_ull(unsigned long long hex, char *hexdigits, int *bytes)
{
	if (hex >= 16)
	{
		ft_puthex_ull(hex / 16, hexdigits, bytes);
		ft_puthex_ull(hex % 16, hexdigits, bytes);
	}
	else
	{
		ft_putchar(hexdigits[hex], bytes);
	}
}

void	ft_puthex_uint(unsigned int hex, char *hexdigits, int *bytes)
{
	if (hex >= 16)
	{
		ft_puthex_uint(hex / 16, hexdigits, bytes);
		ft_puthex_uint(hex % 16, hexdigits, bytes);
	}
	else
	{
		ft_putchar(hexdigits[hex], bytes);
	}
}
