/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:58:49 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 19:15:09 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image_for_tile(t_game *game, char tile, char move)
{
	if (tile == '1')
		return (game->img_wall);
	if (tile == '0')
		return (game->img_floor);
	if (tile == 'C')
		return (game->img_collect);
	if (tile == 'E')
		return (game->img_exit);
	if (tile == 'P')
	{
		if (move == 'u')
			return (game->img_player_up);
		if (move == 'd')
			return (game->img_player_down);
		if (move == 'r')
			return (game->img_player_right);
		if (move == 'l')
			return (game->img_player_left);
	}
	return (game->img_floor);
}

void	render_map(t_game *game, char move)
{
	int		x;
	int		y;
	void	*img;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (game->map_file[y])
	{
		x = 0;
		while (game->map_file[y][x])
		{
			img = get_image_for_tile(game, game->map_file[y][x], move);
			mlx_put_image_to_window(game->mlx, game->win,
				img, x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}
