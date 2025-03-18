/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:07:30 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:47:30 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = NULL;

	while (n-- > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			p = s;
			break ;
		}
		s = (unsigned char *)s + 1;
	}
	return ((void *)p);
}

// int	main(void)
// {
// char	*a;
// char	p[4] = "hola";
//
// a = ft_memchr(p, 'o', 4);
// printf("%s", a);
// return (0);
// }
