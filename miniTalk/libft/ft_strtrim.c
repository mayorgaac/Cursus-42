/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:30:11 by amayorga          #+#    #+#             */
/*   Updated: 2024/05/08 16:50:35 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	return (i);
}

int	ft_trim_end(char const *s1, char const *set, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && ft_is_in_set(s1[i], set))
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		end;
	int		i;
	char	*rst;

	len = ft_strlen(s1);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set, len);
	if (start > end)
		end = start;
	rst = (char *)malloc((sizeof(char)) * (end - start + 1));
	if (!rst)
		return (0);
	i = 0;
	while (start < end)
	{
		rst[i] = s1[start];
		i++;
		start++;
	}
	rst[i] = '\0';
	return (rst);
}
