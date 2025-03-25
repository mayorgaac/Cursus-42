/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:52:50 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/25 20:55:34 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
}

void	print_map_debug(char **map)
{
	int	y;
	int	x;

	y = 0;
	if (!map)
		return ;
	while (map[y])
	{
		ft_printf("Línea %d: ", y);
		x = 0;
		while (map[y][x])
		{
			ft_printf("[%c]", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
