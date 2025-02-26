#include "../so_long.h"

void calculate_size(t_game *game)
{
  int x;
  int width;
  int height;

  if(!game->map_file)
    return;
  height = 0;
  width = 0;
  x = 0;
  while(game->map_file[x])
  {
    height++;
    x++;
  }
  x = 0;
  if(height > 0)
  {
    while(game->map_file[0][x])
    {
      width++;
      x++;
    }
  }
  game->width = width;
  game->height = height;
}

char **map_copy(char **map, int height)
{
  char **map_copy;
    int i;

    map_copy = malloc(sizeof(char *) * (height + 1));
    if (!map_copy)
        return (NULL);

    i = 0;
    while (map[i])
    {
        map_copy[i] = ft_strdup(map[i]);
        if (!map_copy[i])
        {
            while (i--)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    map_copy[i] = NULL;
    return map_copy;
}
