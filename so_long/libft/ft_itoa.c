/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:36:32 by amayorga          #+#    #+#             */
/*   Updated: 2024/03/15 21:36:34 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	i;
	int	temp;

	temp = n;
	i = 1;
	if (temp < 0)
	{
		temp = temp * -1;
		i++;
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*c;
	int			nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nlen(n);
	c = (char *)malloc((sizeof(char)) * (len + 1));
	nb = n;
	if (!c)
		return (NULL);
	c[len--] = 0;
	if (nb < 0)
	{
		c[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		c[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (c);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nb = 12;
	printf("ft_itoa: %s\n", ft_itoa(nb));
	printf("itoa: %s\n", itoa(nb));
}*/
