/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:02:50 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/25 12:08:02 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	if (c != 'P' && c != '0' && c != 'C' && c != 'E')
		return (0);
	else
		return (1);
}

void	fill(char **map, t_position size, t_position curr, t_map *game)
{
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

void	flood_fill(char **map, t_position size, t_position begin, t_map *game)
{
	fill(map, size, begin, game);
}
