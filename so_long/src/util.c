#include "../so_long.h"

void calculate_size(char **map_file, int *width, int *height)
{
  int x;

  *height = 0;
  *width = 0;
  x = 0;
  while(map_file[x])
  {
    (*height)++;
    x++;
  }
  x = 0;
  if(*height > 0)
  {
    while(map_file[0][x])
    {
      (*width)++;
      x++;
    }
  }
}
