#ifndef SO_LONG_H
  #define SO_LONG_H

  #include "mlx.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h> //ELIMINAR ESTE INCLUDE

  #define WIDTH 800
  #define HEIGHT 600

  typedef struct s_game
  {
    void *mlx;
    void *win;
    void *img_wall;
    void *img_floor;
    void *img_collect;
    void *img_player;
    void *img_exit;
    int img_width;
    int img_height;
    int width;
    int height;
    char **map_file;
    int player_x;
    int player_y;
    int colleccionables;
    int final_x;
    int final_y;
  } t_game;

  //mapa.c
  void draw_map(t_game *game);
  void load_images(t_game *game);
  //util.c
  void calculate_size(char **map_file, int *width, int *height);
  //check.c
  int check_map(char **map, int *width, int *height);
  int check_caracters(char **map);
  int check_rectangular(char **map, int width, int height);
  int check_reachability(char **map, int width, int height);
  void search_initial_point(char **map, int *start_y, int *start_x);
  void flood_fill(char **map, int x, int y, int width, int height);
  void free_array(char **map);
  //print.c
  void print_game(char **map);
  //game_control.c
  int handle_key(int key, t_game *game);
  void setup_hooks(t_game *game);
  void exit_game(t_game *game);
  void move_player(t_game *game, int dx, int dy);
  void render_map(t_game *game);



#endif
