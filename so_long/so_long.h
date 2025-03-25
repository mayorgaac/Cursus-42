#ifndef SO_LONG_H
  #define SO_LONG_H

  #include "mlx.h"
  #include "libft/libft.h"
  #include "libft/printf/ft_printf.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <fcntl.h>
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
    void *img_player_up;
    void *img_player_down;
    void *img_player_right;
    void *img_player_left;
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
  void load_images(t_game *game);
  void *select_image(t_game *game, char tile, int x, int y);
  void draw_map(t_game *game);
  void init_data_game(t_game *game);
  char	**allocate_map(int fd, int num_lines);
  int	fill_map(int fd, char **map);
  char **read_map_from_file(char *filename);
  int read_lines_of_file(char *filename);
  void remove_newline(char *line);
  //util.c
  void calculate_size(t_game *game);
  char **copy_map(char **map, int height);
  //check.c
  int check_map(char **map, int *width, int *height);
  int check_caracters(char **map);
  int check_rectangular(char **map, int width, int height);
  int check_reachability(char **map, int width, int height);
  void search_initial_point(char **map, int *start_y, int *start_x);
  void flood_fill(char **map, int x, int y, int width, int height);
  //print.c
  void print_map(char **map);
  void print_map_debug(char **map);
  //game_control.c
  int handle_key(int key, t_game *game);
  void setup_hooks(t_game *game);
  int exit_game(t_game *game);
  void move_player(t_game *game, int dx, int dy, char move);
  void render_map(t_game *game, char move);
  //frees.c
  void free_map(char **map);
  void free_images(t_game *game);
  //init.c
  int	check_args(int argc);
  int	load_game(t_game **game, char *map_path);
  int	init_window(t_game *game);


#endif
