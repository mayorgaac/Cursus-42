/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:01:45 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:01:52 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	if (n > 0)
	{
		while (n-- > 0)
			*ptr++ = 0;
		return ;
	}
	else
	{
		return ;
	}
}

// int	main(void)
// {
// int i = 0;
// int array[5];
// ft_bzero(array, 5);
// while (i++ < 5)
// printf("%d", array[0]);
// return (0);
// }
