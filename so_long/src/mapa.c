/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:04:48 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/25 21:05:36 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_images(t_game *game)
{
  game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/asteroide.xpm", &game->img_width, &game->img_height);
  game->img_floor = mlx_xpm_file_to_image(game->mlx, "images/fondo.xpm", &game->img_width, &game->img_height);
  game->img_collect = mlx_xpm_file_to_image(game->mlx, "images/estrella.xpm", &game->img_width, &game->img_height);
  game->img_player_up = mlx_xpm_file_to_image(game->mlx, "images/nave_up.xpm", &game->img_width, &game->img_height);
  game->img_player_down = mlx_xpm_file_to_image(game->mlx, "images/nave_down.xpm", &game->img_width, &game->img_height);
  game->img_player_right = mlx_xpm_file_to_image(game->mlx, "images/nave_right.xpm", &game->img_width, &game->img_height);
  game->img_player_left = mlx_xpm_file_to_image(game->mlx, "images/nave_left.xpm", &game->img_width, &game->img_height);
  game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/planeta.xpm", &game->img_width, &game->img_height);

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
	int	x;
	int	y;

	game->colleccionables = 0;
	y = 0;
	while (game->map_file[y])
	{
		x = 0;
		while (game->map_file[y][x])
		{
			void *img = select_image(game, game->map_file[y][x], x, y);
			mlx_put_image_to_window(game->mlx, game->win, img, x * game->img_width, y * game->img_height);
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
}

char	**allocate_map(int fd, int num_lines)
{
	char	**map;

	map = malloc(sizeof(char *) * (num_lines + 1));
	if (!map)
		return (close(fd), NULL);
	return (map);
}

int	fill_map(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		remove_newline(line);
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
			return (-1);
		i++;
	}
	map[i] = NULL;
	return (0);
}

char	**read_map_from_file(char *filename)
{
    int	fd;
    int	num_lines;

    num_lines = read_lines_of_file(filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (ft_printf("Error: No se pudo abrir el archivo %s\n", filename), NULL);
    char **map = allocate_map(fd, num_lines);
    if (!map)
		return (NULL);
    if (fill_map(fd, map) == -1)
	{
		while (num_lines-- > 0)
			free(map[num_lines]);
		free(map);
		return (close(fd), NULL);
	}
	close(fd);
	return (map);
}

int read_lines_of_file(char *filename)
{
	int		lines;
	int		fd;
	char	*line;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: No se pudo abrir el archivo %s\n", filename);
		return (0);
	}
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

void	remove_newline(char *line)
{
	int	len;

	len = 0;
	if (!line)
		return ;
	while (line[len])
		len++;
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return ;
}
