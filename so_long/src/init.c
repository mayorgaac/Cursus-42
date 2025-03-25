/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:05:21 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/25 20:25:53 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("USO: ./so_long mapa.ber\n");
		return (0);
	}
	return (1);
}

int	load_game(t_game **game, char *map_path)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (ft_printf("ERROR\n"), 0);
	init_data_game(*game);
	(*game)->map_file = read_map_from_file(map_path);
	if (!(*game)->map_file)
		return (free(*game), ft_printf("ERROR\n"), 0);
	calculate_size(*game);
	if (!check_map((*game)->map_file, &(*game)->width, &(*game)->height))
		return (free_map((*game)->map_file), free(*game),
			ft_printf("ERROR: Mapa inválido.\n"), 0);
	return (1);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("ERROR: No se pudo inicializar MiniLibX.\n"),
			free_map(game->map_file), free(game), 0);
	game->win = mlx_new_window(game->mlx,
			game->width * 32, game->height * 32, "So Long");
	if (!game->win)
		return (ft_printf("ERROR: No se pudo crear la ventana.\n"),
			free_map(game->map_file), free(game), 0);
	return (1);
}
