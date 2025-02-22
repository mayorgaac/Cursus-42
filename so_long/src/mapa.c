#include "../so_long.h"

void load_images(t_game *game)
{
  game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/asteroide.xpm", &game->img_width, &game->img_height);
  game->img_floor = mlx_xpm_file_to_image(game->mlx, "images/fondo.xpm", &game->img_width, &game->img_height);
  game->img_collect = mlx_xpm_file_to_image(game->mlx, "images/estrella.xpm", &game->img_width, &game->img_height);
  game->img_player = mlx_xpm_file_to_image(game->mlx, "images/nave.xpm", &game->img_width, &game->img_height);
  game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/planeta.xpm", &game->img_width, &game->img_height);

  if(!game->img_wall || !game->img_floor || !game->img_collect || !game->img_player || !game->img_exit)
  {
    //ft_printf("ERROR: No se puedieron cargar las imagenes.\n")
    exit(1);
  }
}

void draw_map(t_game *game)
{
  int x;
  int y;

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
        img = game->img_player;
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
