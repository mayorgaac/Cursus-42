/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:30:06 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/06 18:47:30 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == d)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == d)
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char array[5] = "holo*";
// 	char *p;

// 	p = ft_strrchr(array, 'o');
// 	printf("%s", p);
// 	return (0);
// }