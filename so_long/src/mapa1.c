/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:42:10 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/31 18:49:45 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	fill_map(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_newline(line);
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
			return (-1);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (0);
}

char	**read_map_from_file(char *filename)
{
	int		fd;
	int		num_lines;
	char	**map;

	num_lines = read_lines_of_file(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: No se pudo abrir el archivo %s\n",
				filename), NULL);
	map = allocate_map(fd, num_lines);
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

int	read_lines_of_file(char *filename)
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
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
