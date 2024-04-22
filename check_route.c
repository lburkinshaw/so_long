/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:15:55 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/22 12:05:47 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**make_area(char **zone, t_position size)
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

static int	check_fill(char **map, t_map *game)
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
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_route(t_map *game)
{
	t_position	size;
	char		**fill_map;
	// int			tmp_collect;

	size.x = game->columns;
	size.y = game->rows;
	fill_map = make_area(game->map, size);
	// tmp_collect = game->collectibles;
	flood_fill(fill_map, size, game->player_pos, game);
	// game->collectibles = tmp_collect;
	if (check_fill(fill_map, game) == 1)
	{
		free_array(fill_map);
		return (1);
	}
	free_array(fill_map);
	return (0);
}
