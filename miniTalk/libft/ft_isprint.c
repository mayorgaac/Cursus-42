/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:05:50 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:47:30 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int	main(void)
// {
// int		i;
// char	array[11] = "H123 Z{}~**";
//
// i = 0;
// while (array[i] != '\0')
// {
// printf("%d", ft_isprint((int)array[i]));
// i++;
// }
// return (0);
// }
