/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:59:00 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:37:26 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key(int key, t_game *game)
{
	if (key == 65307)
		return (exit_game(game));
	else if (key == 119 || key == 65362)
		move_player(game, 0, -1, 'u');
	else if (key == 115 || key == 65364)
		move_player(game, 0, 1, 'd');
	else if (key == 97 || key == 65361)
		move_player(game, -1, 0, 'l');
	else if (key == 100 || key == 65363)
		move_player(game, 1, 0, 'r');
	return (0);
}

void	destroy_images(t_game *game)
{
	int		i;
	void	*images[8];

	if (!game)
		return ;
	images[0] = game->img_player_up;
	images[1] = game->img_player_down;
	images[2] = game->img_player_right;
	images[3] = game->img_player_left;
	images[4] = game->img_wall;
	images[5] = game->img_floor;
	images[6] = game->img_collect;
	images[7] = game->img_exit;
	i = 0;
	while (i < 8)
	{
		if (images[i])
			mlx_destroy_image(game->mlx, images[i]);
		i++;
	}
}

int	exit_game(t_game *game)
{
	if (!game)
		return (0);
	if (game->map_file)
		free_map(game->map_file);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}

void	move_player(t_game *game, int dx, int dy, char move)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map_file[new_y][new_x] == '1' || new_x < 0
		|| new_x >= game->width || new_y < 0 || new_y >= game->height)
		return ;
	if (game->map_file[new_y][new_x] == 'C')
		game->colleccionables--;
	if (game->map_file[new_y][new_x] == 'E' && game->colleccionables == 0)
		exit_game(game);
	else if (game->map_file[new_y][new_x] == 'E' && game->colleccionables > 0)
		return ;
	game->map_file[game->player_y][game->player_x] = '0';
	game->map_file[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->total_moves++;
	ft_printf("Total de movimientos: %d\n", game->total_moves);
	render_map(game, move);
}
