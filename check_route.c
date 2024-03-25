/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:15:55 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/25 12:21:21 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	**make_area(char **zone, t_position size)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (size.y + 1));
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
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	check_fill(char **map, t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				free_array(map);
				error_n_exit("Error: invalid path\n", game);
			}
			x++;
		}
		y++;
	}
	ft_printf("Valid path\n");
}

void	check_route(t_map *game)
{
	t_position	size;
	char		**fill_map;
	int			i;
	int			rows;
	int			tmp_collect;

	size.x = game->columns;
	size.y = game->rows;//this seems the opposite to other coords but works
	fill_map = make_area(game->map, size);
	i = 0;
	rows = game->rows;
	ft_printf("map to fill:\n");/* DELETE*/
	while (i < rows)/* DELETE*/
	{
		ft_printf("%s\n", fill_map[i]);
		i++;
	}
	ft_printf("player position; y=%d, x=%d\n", game->player.y, game->player.x);/* DELETE*/
	tmp_collect = game->collectibles;
	flood_fill(fill_map, size, game->player, game);
	game->collectibles = tmp_collect;
	ft_printf("filled map:\n");/* DELETE*/
	i = 0;
	while (i < rows) /* DELETE*/
	{
		ft_printf("%s\n", fill_map[i]);
		i++;
	}
	check_fill(fill_map, game);
	free_array(fill_map);
}
