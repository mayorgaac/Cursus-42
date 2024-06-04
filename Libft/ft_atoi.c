/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:59:25 by amayorga          #+#    #+#             */
/*   Updated: 2024/03/15 20:59:28 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	s;
	int	val;

	if(!str)
		return(0);
	s = 1;
	val = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	val *= s;
	return (val);
}

/*#include <stdio.h>

int main()
{
	char *str = "123 asdasda";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));

	str = " asdasda";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));

	// str = NULL;
	// printf("ft_atoi: %d\n", ft_atoi(str));
	// printf("atoi: %d\n", atoi(str));

	str = "-kgkjhk123 asdasda";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));

	str = "-123 asdasda";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));

	str = "";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));*/
}
