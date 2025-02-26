#include "../so_long.h"

int handle_key(int key, t_game *game)
{
  if(key == 65307) // Tecla ESC para salir
    exit_game(game);
  else if (key == 119 || key == 65362) // 'W' → Mover arriba
    move_player(game, 0, -1, 'u');
  else if (key == 115 || key == 65364) // 'S' → Mover abajo
    move_player(game, 0, 1, 'd');
  else if (key == 97 || key == 65361) // 'A' → Mover izquierda
    move_player(game, -1, 0, 'l');
  else if (key == 100 || key == 65363)  // 'D' → Mover derecha
    move_player(game, 1, 0, 'r');
  return (0);
}

int exit_game(t_game *game)
{
  if(game->map_file)
    free_array(game->map_file);
  if(game->img_player_up)
    mlx_destroy_image(game->mlx, game->img_player_up);
  if(game->img_player_down)
    mlx_destroy_image(game->mlx, game->img_player_down);
  if(game->img_player_right)
    mlx_destroy_image(game->mlx, game->img_player_right);
  if(game->img_player_down)
    mlx_destroy_image(game->mlx, game->img_player_down);
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
  return (0);
}

void setup_hooks(t_game *game)
{
  mlx_key_hook(game->win, handle_key, game);
  mlx_hook(game->win, 17, 0, exit_game, game);
}

void move_player(t_game *game, int dx, int dy, char move)
{
  int new_x;
  int new_y;
  char **copy_map;

  copy_map = map_copy(game->map_file, game->height);
  new_x = game->player_x + dx;
  new_y = game->player_y + dy;
  if(copy_map[new_y][new_x] == '1' || new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
    return;
  if(copy_map[new_y][new_x] == 'C')
    game->colleccionables--;
  if(copy_map[new_y][new_x] == 'E' && game->colleccionables == 0)
    exit_game(game);
  else if(copy_map[new_y][new_x] == 'E' && game->colleccionables > 0)
    return;
  copy_map[game->player_y][game->player_x] = '0';
  copy_map[new_y][new_x] = 'P';
  game->player_x = new_x;
  game->player_y = new_y;
  game->map_file = copy_map;
  //free_array(copy_map);
  render_map(game, move);
}

void render_map(t_game *game, char move)
{
    int x;
    int y;

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
            else if (game->map_file[y][x] == 'P' && move == 'u')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player_up, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'P' && move == 'd')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player_down, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'P' && move == 'r')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player_right, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'P' && move == 'l')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player_left, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x*game->img_width, y * game->img_height);
            else if (game->map_file[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x*game->img_width, y * game->img_height);
            x++;
        }
        y++;
    }

}
