#include "../so_long.h"

int check_map(char **map, int *width, int *height)
{
  print_map(map);
  if(!check_caracters(map) || !check_rectangular(map, *width, *height) || !check_reachability(map, *width, *height))
    return (0);
  return (1);
}

int check_caracters(char **map)
{
  int x;
  int y;
  int count1; //para contar inicio y salida; Igual a 2
  int count2; //para contar objetos; minimo 1

  count1 = 0;
  count2 = 0;
  y = 0;
  while(map[y])
  {
    x = 0;
    while(map[y][x])
    {
      if(map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P')
        return (0);
      if(map[y][x] == 'E' || map[y][x] == 'P')
        count1++;
      if(map[y][x] == 'C')
        count2++;
      x++;
    }
    y++;
  }
  if(count1 != 2 || count2 < 1)
    return(0);
  return (1);
}

int check_rectangular(char **map, int width, int height)
{
  int x;
  int y;
  int current_width;

  x = 0;
  while(x < width)
  {
    if(map[0][x] != '1' && map[height - 1][x] != '1')
      return(0);
    x++;
  }
  y = 0;
  while(map[y])
  {
    current_width = 0;
    while(map[y][current_width])
      current_width++;
    if(current_width != width)
      return(0);
    if(map[y][0] != '1' && map[y][width - 1] != '1')
      return(0);
    y++;
  }
  return (1);
}

int check_reachability(char **map, int width, int height)
{
  int start_x;
  int start_y;
  char **map_copy;
  int i;
  int x;

  search_initial_point(map, &start_y, &start_x);
  map_copy = malloc(height * (sizeof(char *) + 1));
  i = 0;
  while(i < height)
  {
    map_copy[i] = strdup(map[i]); //USAR PROPIO FT_STRDUP
    i++;
  }
  printf("start_x: %d; start_y: %d\n", start_x, start_y);
  printf("width: %d; height: %d\n", width, height);
  flood_fill(map_copy, start_x, start_y, width, height);
  print_map(map_copy);
  i = 0;
  while(map_copy[i])
  {
    x = 0;
    while(map_copy[i][x])
    {
      printf("X: %d, Y:%d\n", x, i);
      if(map_copy[i][x] == 'C' || map_copy[i][x] == 'E')
      {
        free_array(map_copy);
        return (0);
      }
      x++;
    }
    i++;
  }
  free_array(map_copy);
  return(1);
}

void search_initial_point(char **map, int *start_y, int *start_x)
{
  int x;
  int y;

  y = 0;
  while(map[y])
  {
    x = 0;
    while(map[y][x])
    {
      if(map[y][x] == 'P')
      {
        *start_x = x;
        *start_y = y;
        break;
      }
      x++;
    }
    if(*start_x == x)
      break;
    y++;
  }
}

void flood_fill(char **map, int x, int y, int width, int height)
{
  if(x < 0 || y < 0 || x > width || y > height)
    return;
  if(x == width || y == height)
    map[y][x] = '\0';
  if(map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == '\0')
    return;
  map[y][x] = 'F';
  flood_fill(map, x + 1, y, width, height);
  flood_fill(map, x - 1, y, width, height);
  flood_fill(map, x, y + 1, width, height);
  flood_fill(map, x, y - 1, width, height);
}

void free_array(char **map)
{
  int i;

  i = 0;
  while(map[i])
  {
    free(map[i]);
    i++;
  }
  free(map);
}
