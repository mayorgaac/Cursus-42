/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:29:24 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:47:30 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

// void	function(unsigned int index, char *c)
// {
// if (*c >= 'a' && *c <= 'z')
// *c = *c - ('a' - 'A');
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

// int	main(void)
// {
// char str[] = "hola que tal";
// ft_striteri(str, &function);
// printf("%s\n", str);
// return (0);
// }