#include "../so_long.h"

int main(/*int argc, char *argv[]*/)
{
  t_game *game;
  int width;
  int height;

  /*if(argc != 2)
  {
      //ft_printf("USO: ./so_long mapa.ber\n");
      return (0);
  }*/
  game = malloc(sizeof(t_game));
  //char *map_namefile = argv[1];
  //LEER EL ARCHIVO CON LA FUNCION GET_NEXT_LINE
  char *map_raw[] = {
        "111111111111111",
        "10010000000C001",
        "100001111100001",
        "1P0011E00000001",
        "111111111111111",
        NULL
    };
  game->map_file = map_raw;
  calculate_size(game->map_file, &width, &height);
  game->width = width;
  game->height = height;

  if(!check_map(game->map_file, &width, &height)) //No esta haciendo nada por aqui. hay que ver que
  {
      //ft_printf("ERROR: Mapa invalido.\n");
      return (0);
  }

  game->mlx = mlx_init();
  game->win = mlx_new_window(game->mlx, width * 32, height * 32, "So Long");

   load_images(game);
   draw_map(game);
   setup_hooks(game);

   mlx_loop(game->mlx);

  return (0);
}
