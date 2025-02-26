#include "../so_long.h"

void print_map(char **map)
{
  int y;

  y = 0;
  while(map[y])
  {
    ft_printf("%s\n", map[y]);
    y++;
  }
}

void print_map_debug(char **map)
{
  int y = 0;

    while (map[y])
    {
        ft_printf("Línea %d: ", y);
        int x = 0;
        while (map[y][x])
        {
            ft_printf("[%c]", map[y][x]); // Mostrar cada caracter
            x++;
        }
        ft_printf("\n");
        y++;
    }
}
