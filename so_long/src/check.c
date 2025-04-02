/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:23:24 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:48:21 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char **map, t_game *game)
{
	if (!check_caracters(map)
		|| !check_rectangular(map, game->width, game->height)
		|| !check_reachability(map, game))
		return (0);
	return (1);
}

int	check_caracters(char **map)
{
	int	x;
	int	y;
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!is_valid_character(map[y][x]))
				return (0);
			count_elements(map[y][x], &count1, &count2);
		}
	}
	if (count1 != 2 || count2 < 1)
		return (0);
	return (1);
}

int	check_rectangular(char **map, int width, int height)
{
	int	x;
	int	y;
	int	current_width;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (map[y])
	{
		current_width = 0;
		while (map[y][current_width])
			current_width++;
		if (current_width != width)
			return (0);
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	validate_reachability(char **map_copy)
{
	int	i;
	int	x;

	i = 0;
	while (map_copy[i])
	{
		x = 0;
		while (map_copy[i][x])
		{
			if (map_copy[i][x] == 'C' || map_copy[i][x] == 'E')
			{
				ft_printf("ERROR de accesibilidad en la línea %d, columna %d\n",
					i, x);
				free_map(map_copy);
				return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}

int	check_reachability(char **map, t_game *game)
{
	int		start_x;
	int		start_y;
	char	**map_copy;

	start_x = 0;
	start_y = 0;
	search_initial_point(map, &start_y, &start_x);
	map_copy = copy_map(map, game->height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, start_x, start_y, game);
	if (!validate_reachability(map_copy))
		return (0);
	free_map(map_copy);
	return (1);
}
