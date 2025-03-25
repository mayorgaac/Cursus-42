/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:02:05 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/25 21:16:11 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

void	*ft_calloc(int count, int size)
{
	void	*p;

	p = (void *)malloc(count * size);
	if (p != NULL)
	{
		p = ft_memset(p, 0, count * size);
		return (p);
	}
	return (NULL);
}

// int	main(void)
// {
// void	*p;
//
// p = ft_calloc(4, sizeof(int));
// if (p != NULL)
// {
// printf("%d", *(int *)p);
// return (0);
// }
// return (1);
// }
