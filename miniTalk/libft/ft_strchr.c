/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:29:19 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/04 20:57:30 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Se utiliza para buscar la primera
//aparición de un carácter específico en una cadena de texto.

//Devuelve un puntero al primer carácter encontrado 
//en la cadena o NULL si no lo encuentra

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	int				i;

	d = c;
	i = 0;
	while ((s[i]) || (i == 0))
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	if (d == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
