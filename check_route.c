
#include "so_long.h"

int valid_char(char c)
{
    if (c != 'P' && c != '0' && c != 'C' && c != 'E')
        return (0);
    else
        return (1);
}

void fill(char **map, t_position size, t_position curr, t_map *game)
{
    ft_printf("Visiting position (%d, %d)\n", curr.y, curr.x);
    if (curr.y < 0 || curr.y >= size.y || curr.x < 0 || curr.x >= size.x
		|| valid_char(map[curr.y][curr.x]) == 0) //check whether out of bounds or isnt correct character
		return ;
    if (map[curr.y][curr.x] == 'E' && game->collectibles == 0)
        map[curr.y][curr.x] = 'F';//changes to F to indicate filled
	if (map[curr.y][curr.x] == 'C')
    {
        game->collectibles--;
        map[curr.y][curr.x] = 'F';//changes to F to indicate filled
    }
    if (map[curr.y][curr.x] == '0' || map[curr.y][curr.x] == 'P')
        map[curr.y][curr.x] = 'F';//changes to F to indicate filled
	fill(map, size, (t_position){curr.x - 1, curr.y}, game);//recursive call for position LEFT
	fill(map, size, (t_position){curr.x + 1, curr.y}, game);//recursive call for position RIGHT
	fill(map, size, (t_position){curr.x, curr.y - 1}, game);//recursive call for position ABOVE
	fill(map, size, (t_position){curr.x, curr.y + 1}, game);//recursive call for position BELOW
	//Recursion continues until no adjacent positions to be filled.
}

void  flood_fill(char **map, t_position size, t_position begin, t_map *game)
{
	fill(map, size, begin, game);
}

char** make_area(char** zone, t_position size)
{
	char** new;
    int i;

    i = 0;
    new = malloc(sizeof(char*) * (size.y));
    if (new == NULL)
        return (NULL);
	while (i < size.y)
    {
        new[i] = ft_strdup(zone[i]);
        if (new[i] == NULL)
        {
            while (i > 0)
                free(new[--i]);
            free(new);
            return NULL;
        }
        i++;
    }
    return (new);
}

void    check_fill(char **map, t_map *game)
{
    int y = 0;
    int x;
    while (y < game->rows)
    {
        x = 0;
         while (x < game->columns)
         {
            if (map[y][x] == 'E' || map[y][x] == 'C')
                error_n_exit("Error: invalid path\n", game);
            x++;
         }
         y++;
    }
    ft_printf("Valid path\n");
}

void    check_route(t_map *game)
{
    t_position size = {game->columns, game->rows};//this seems the opposite to other coords but works
    char **fill_map = make_area(game->map, size);
    int i = 0;
    int rows = game->rows;
    ft_printf("map to fill:\n");
    while (i < rows) 
    {
        ft_printf("%s\n", fill_map[i]);
        i++;
    }
    ft_printf("player position; y=%d, x=%d\n", game->player.y, game->player.x);
    int tmp_collect = game->collectibles;
    flood_fill(fill_map, size, game->player, game);
    game->collectibles = tmp_collect;
    ft_printf("filled map:\n");
    i = 0;
    while (i < rows) 
    {
        ft_printf("%s\n", fill_map[i]);
        i++;
    }
    check_fill(fill_map, game);
}
