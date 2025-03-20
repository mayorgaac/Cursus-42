/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:57:27 by amayorga          #+#    #+#             */
/*   Updated: 2024/06/18 19:00:02 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *bytes)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", bytes);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', bytes);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, bytes);
		}
		ft_putchar((n % 10) + '0', bytes);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *bytes)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, bytes);
	}
	ft_putchar((n % 10) + '0', bytes);
}
