/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:04:48 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 18:45:59 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/asteroide.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/fondo.xpm", &game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/estrella.xpm", &game->img_width, &game->img_height);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/nave_up.xpm", &game->img_width, &game->img_height);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/nave_down.xpm", &game->img_width, &game->img_height);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/nave_right.xpm", &game->img_width, &game->img_height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/nave_left.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/planeta.xpm", &game->img_width, &game->img_height);
	if (!game->img_wall || !game->img_floor || !game->img_collect
		|| !game->img_player_up || !game->img_player_down
		|| !game->img_player_right || !game->img_player_left || !game->img_exit)
	{
		ft_printf("ERROR: No se puedieron cargar las imagenes.\n");
		free_images(game);
		exit(1);
	}
}

void	*select_image(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		return (game->img_wall);
	if (tile == 'C')
	{
		game->colleccionables++;
		return (game->img_collect);
	}
	if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		return (game->img_player_up);
	}
	if (tile == 'E')
		return (game->img_exit);
	return (game->img_floor);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	game->colleccionables = 0;
	y = 0;
	while (game->map_file[y])
	{
		x = 0;
		while (game->map_file[y][x])
		{
			img = select_image(game, game->map_file[y][x], x, y);
			mlx_put_image_to_window(game->mlx, game->win,
				img, x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}

void	init_data_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_collect = NULL;
	game->img_player_up = NULL;
	game->img_player_down = NULL;
	game->img_player_right = NULL;
	game->img_player_left = NULL;
	game->img_exit = NULL;
	game->img_width = 0;
	game->img_height = 0;
	game->width = 0;
	game->height = 0;
	game->map_file = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->colleccionables = 0;
	game->final_x = 0;
	game->final_y = 0;
	game->total_moves = 0;
}

char	**allocate_map(int fd, int num_lines)
{
	char	**map;

	map = malloc(sizeof(char *) * (num_lines + 1));
	if (!map)
		return (close(fd), NULL);
	return (map);
}
