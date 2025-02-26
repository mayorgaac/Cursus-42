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

  if(!game->img_wall || !game->img_floor || !game->img_collect || !game->img_player_up || !game->img_player_down || !game->img_player_right || !game->img_player_left || !game->img_exit)
  {
    ft_printf("ERROR: No se puedieron cargar las imagenes.\n");
    exit(1);
  }
}

void draw_map(t_game *game)
{
  int x;
  int y;

  if(game == NULL)
  {
    ft_printf("GAME NULL");
    return;
  }
  y = 0;
  while(game->map_file[y])
  {
    x = 0;
    while(game->map_file[y][x])
    {
      void *img = game->img_floor;
      if(game->map_file[y][x] == '1')
        img = game->img_wall;
      else if(game->map_file[y][x] == 'C')
      {
        img = game->img_collect;
        game->colleccionables++;
      }
      else if(game->map_file[y][x] == 'P')
      {
        img = game->img_player_up;
        game->player_x = x;
        game->player_y = y;
      }
      else if(game->map_file[y][x] == 'E')
      {
        img = game->img_exit;
      //  game->final_x = x;
      //  game->final_y = y;
      }

      mlx_put_image_to_window(game->mlx, game->win, img, x*game->img_width, y * game->img_height);
      x++;
    }
    y++;
  }
}

char **read_map_from_file(char *filename)
{
    int fd;
    int num_lines;
    char *line;

    num_lines = read_lines_of_file(filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: No se pudo abrir el archivo %s\n", filename);
        return NULL;
    }

    char **map = malloc(sizeof(char *) * (num_lines + 1)); // Suponiendo que el mapa no tiene más de 100 líneas
    if (!map)
        return NULL;

    int i = 0;
    while ((line = get_next_line(fd))) // Lee línea por línea
    {
      line = remove_newline(line);
      map[i] = ft_strdup(line);
      free(line);
      if(!map[i])
      {
        while(i-- > 0)
          free(map[i]);
        free(map);
        close(fd);
        return NULL;
      }
      i++;
    }
    map[i] = NULL; // Termina la lista con NULL

    close(fd);
    return map;
}

int read_lines_of_file(char *filename)
{
  int lines;
  int fd;

  lines = 0;
  fd = open(filename, O_RDONLY);
  if (fd < 0)
  {
      ft_printf("Error: No se pudo abrir el archivo %s\n", filename);
      return 0;
  }
  while(get_next_line(fd))
    lines++;
  close(fd);
  return (lines);
}

char *remove_newline(char *line)
{
    int len = 0;
    while (line[len])
        len++;
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
    return line;
}
