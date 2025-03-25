/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:07:45 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/08 14:01:26 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "stdio.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dest;

	if (!dst && !src)
		return (0);
	dest = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	else
		while (len--)
			*(char *)dst++ = *(char *)src++;
	return (dest);
}

// int	main(void)
// {
// 	char array[10] = "1234567890";
// 	ft_memmove(array, array + 2, 7);
// 	printf("%s", array);
// 	return (0);
// }