#include "../so_long.h"

int main(int argc, char *argv[])
{
  t_game *game;

  if(argc != 2)
  {
      ft_printf("USO: ./so_long mapa.ber\n");
      return (0);
  }
  game = malloc(sizeof(t_game));
  if(!game)
  {
    ft_printf("ERROR");
    return (0);
  }
  init_game(game);
  game->map_file = read_map_from_file(argv[1]);
  //print_map_debug(game->map_file);

  calculate_size(game);

  if(!check_map(game->map_file, &game->width, &game->height)) //check_reachability no esta funcionando (FLOOD_FILL PROBLEMATICO)
  {
    ft_printf("ERROR: Mapa invalido.\n");
    free_map(game->map_file);
    free(game);
    return (0);
  }

  game->mlx = mlx_init();
  if (!game->mlx)
  {
      ft_printf("ERROR: No se pudo inicializar MiniLibX.\n");
      free_map(game->map_file);
      free(game);
      return (1);
  }
  game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "So Long");
  if (!game->win)
  {
      ft_printf("ERROR: No se pudo crear la ventana.\n");
      free_map(game->map_file);
      free(game);
      return (1);
  }

  load_images(game);
  draw_map(game);
  setup_hooks(game);
  mlx_loop(game->mlx);


  return (0);
}
