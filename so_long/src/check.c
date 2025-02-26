#include "../so_long.h"

int check_map(char **map, int *width, int *height)
{
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
  map_copy = malloc(height * (sizeof(char *)));
  if(!map_copy)
    return (0);
  i = 0;
  while(i < height)
  {
    map_copy[i] = ft_strdup(map[i]);
    if(!map_copy[i])
    {
      while (--i >= 0)
        free(map_copy[i]);
      free(map_copy);
      return (0);
    }
    i++;
  }
  flood_fill(map_copy, start_x, start_y, width, height);
  print_map_debug(map_copy);
  i = 0;
  while(map_copy[i])
  {
    x = 0;
    while(map_copy[i][x])
    {
      ft_printf("Verificando mapa: x = %d, i = %d, valor = %c\n", x, i, map_copy[i][x]);
      if(map_copy[i][x] == 'C' || map_copy[i][x] == 'E')
      {
        ft_printf("No se puede alcanzar C o E en la línea %d, columna %d\n", i, x);
        free_map(map_copy);
        return (0);
      }
      x++;
    }
    i++;
  }
  ft_printf("LLEGO AQUI\n");
  free_map(map_copy);
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
  if(x < 0 || y < 0 || x >= width || y >= height)
  {
    ft_printf("Out of bounds: x = %d, y = %d\n", x, y);
    return;
  }
  if(map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == '\0')
  {
    ft_printf("Blocked: x = %d, y = %d, value = %c\n", x, y, map[y][x]);
    return;
  }
  map[y][x] = 'F';
  ft_printf("Flood filling: x = %d, y = %d, value = F\n", x, y);
  flood_fill(map, x + 1, y, width, height);
  flood_fill(map, x - 1, y, width, height);
  flood_fill(map, x, y + 1, width, height);
  flood_fill(map, x, y - 1, width, height);
}
