/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:03:22 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:03:28 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include "stdio.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int		i;
	char	array[11] = "H123 Z{}~**";

	i = 0;
	while (array[i] != '\0')
	{
		printf("%d", ft_isascii((int)array[i]));
		i++;
	}
	return (0);
}*/
