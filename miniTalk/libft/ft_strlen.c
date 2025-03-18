/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:29:48 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/04 20:57:40 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

int	ft_strlen(const char *s)
{
	const char	*p;
	int			i;

	p = s;
	i = 0;
	while (*p != '\0')
	{
		i++;
		p++;
	}
	return (i);
}

// int	main(void)
// {
// size_t i;
// const char array[19] = "Hola\n";
// printf("%zu", i = ft_strlen(array));
// return (0);
// }