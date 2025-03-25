/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:11:45 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/25 20:57:05 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (!check_args(argc))
		return (1);
	if (!load_game(&game, argv[1]))
		return (1);
	if (!init_window(game))
		return (1);
	load_images(game);
	draw_map(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
