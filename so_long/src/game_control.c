#include "../so_long.h"

int handle_key(int key, t_game *game)
{
  if(key == 65307) // Tecla ESC para salir
    exit_game(game);
  else if (key == 119) // 'W' → Mover arriba
    move_player(game, 0, -1);
  else if (key == 115) // 'S' → Mover abajo
    move_player(game, 0, 1);
  else if (key == 97)  // 'A' → Mover izquierda
    move_player(game, -1, 0);
  else if (key == 100) // 'D' → Mover derecha
    move_player(game, 1, 0);
  return (0);
}

void setup_hooks(t_game *game)
{
    mlx_key_hook(game->win, handle_key, game);
//    mlx_hook(game->win, 17, 0, exit_game, game);
}

void exit_game(t_game *game)
{
  if(game->map_file)
    free_array(game->map_file);
  if(game->img_player)
    mlx_destroy_image(game->mlx, game->img_player);
  if (game->img_wall)
    mlx_destroy_image(game->mlx, game->img_wall);
  if (game->img_collect)
    mlx_destroy_image(game->mlx, game->img_collect);
  if (game->img_exit)
    mlx_destroy_image(game->mlx, game->img_exit);
  if (game->win)
    mlx_destroy_window(game->mlx, game->win);
  if (game->mlx)
  {
    mlx_destroy_display(game->mlx);
    free(game->mlx);
  }
  exit(0);
}

void move_player(t_game *game, int dx, int dy)
{
  int new_x;
  int new_y;

  printf("LLEGO AQUI");
  new_x = game->player_x + dx;
  new_y = game->player_y + dy;
  if(game->map_file[new_y][new_x] == '1' || new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
    return;
  if(game->map_file[new_y][new_x] == 'C')
    game->colleccionables--;
  if(game->map_file[new_y][new_x] == 'E' && game->colleccionables == 0)
    exit_game(game);
  else if(game->map_file[new_y][new_x] == 'E' && game->colleccionables > 0)
    return;
  game->map_file[game->player_y][game->player_x] = '0';
  game->map_file[new_y][new_x] = 'P';
  game->player_x = new_x;
  game->player_y = new_y;
  render_map(game);
}

void render_map(t_game *game)
{
    int x;
    int y;

    printf("LLEGO AQUI");
    mlx_clear_window(game->mlx, game->win);
    y = 0;
    while (game->map_file[y])
    {
        x = 0;
        while (game->map_file[y][x])
        {
            if (game->map_file[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x*game->img_width, y * game->img_height);
            x++;
        }
        y++;
    }

}
