/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:08:43 by amayorga          #+#    #+#             */
/*   Updated: 2024/06/18 18:58:15 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *bytes)
{
	write(1, &c, 1);
	(*bytes)++;
}

void	ft_putstr(char *str, int *bytes)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		ft_putstr("(null)", bytes);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], bytes);
		i++;
	}
}
