/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:29:52 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:37:02 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_size(t_game *game)
{
	int	x;
	int	width;
	int	height;

	height = 0;
	width = 0;
	x = 0;
	while (game->map_file[x])
	{
		height++;
		x++;
	}
	x = 0;
	if (height > 0)
	{
		while (game->map_file[0][x])
		{
			width++;
			x++;
		}
	}
	game->width = width;
	game->height = height;
}

char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i--)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void	count_elements(char c, int *count1, int *count2)
{
	if (c == 'E' || c == 'P')
		(*count1)++;
	else if (c == 'C')
		(*count2)++;
}
