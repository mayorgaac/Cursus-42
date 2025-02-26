/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:56:29 by amayorga          #+#    #+#             */
/*   Updated: 2024/06/18 18:59:57 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *bytes)
{
	unsigned long long	ptr_num;

	if (ptr == 0)
	{
		ft_putstr("(nil)", bytes);
		return ;
	}
	ptr_num = (unsigned long long)ptr;
	ft_putstr("0x", bytes);
	ft_puthex_ull(ptr_num, "0123456789abcdef", bytes);
}
