/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:30:02 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/08 14:01:26 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack_mem;
	const char	*needle_mem;
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = len;
		haystack_mem = haystack;
		needle_mem = needle;
		while (i-- > 0 && *haystack_mem && *needle_mem
			&& *haystack_mem == *needle_mem)
		{
			haystack_mem++;
			needle_mem++;
		}
		if (*needle_mem == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

// int	main(void)
// {
// char	*p;

// p = ft_strnstr("Hola que estas", "que", 12);
// printf("%s", p);
// return (0);
// }
