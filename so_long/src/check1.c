/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:29:21 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:44:35 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	search_initial_point(char **map, int *start_y, int *start_x)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				break ;
			}
			x++;
		}
		if (*start_x == x)
			break ;
		y++;
	}
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (!map || x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == '\0')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}
