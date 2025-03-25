/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:02:36 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:02:39 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

int	ft_isalnum(int c)
{
	unsigned char	d;

	d = c;
	if ((d >= 65 && d <= 90) || (d >= 97 && d <= 122) || (d >= 48 && d <= 57))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// int		i;
// char	array[11] = "H123 Z{}~**";
//
// i = 0;
// while (array[i] != '\0')
// {
// printf("%d", ft_isalnum((int)array[i]));
// i++;
// }
// return (0);
// }
