#include "../so_long.h"

void print_map(char **map)
{
  int y;

  y = 0;
  while(map[y])
  {
    printf("%s\n", map[y]);
    y++;
  }
}
