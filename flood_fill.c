/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:02:50 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 14:24:58 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_char(char c)
{
	if (c != 'P' && c != '0' && c != 'C' && c != 'E')
		return (0);
	else
		return (1);
}

void	fill(char **map, t_position size, t_position curr, t_map *game)
{
	if (curr.y < 0 || curr.y >= size.y || curr.x < 0 || curr.x >= size.x
		|| valid_char(map[curr.y][curr.x]) == 0)
		return ;
	if (map[curr.y][curr.x] == 'E')
		map[curr.y][curr.x] = 'F';
	if (map[curr.y][curr.x] == 'C')
	{
		game->collectibles--;
		map[curr.y][curr.x] = 'F';
	}
	if (map[curr.y][curr.x] == '0' || map[curr.y][curr.x] == 'P')
		map[curr.y][curr.x] = 'F';
	fill(map, size, (t_position){curr.x - 1, curr.y}, game);
	fill(map, size, (t_position){curr.x + 1, curr.y}, game);
	fill(map, size, (t_position){curr.x, curr.y - 1}, game);
	fill(map, size, (t_position){curr.x, curr.y + 1}, game);
}

void	flood_fill(char **map, t_position size, t_position begin, t_map *game)
{
	fill(map, size, begin, game);
}
