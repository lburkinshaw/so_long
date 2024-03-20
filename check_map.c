/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:34:07 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 12:28:19 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map	*game)
{
	int	i;
	int	last;
	i = 0;
	last = game->rows - 1;
	//check first row, last row - all 1
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[last][i] != '1')
			error_n_exit("Error: incomplete walls.\n", game);
		i++;
	}
	// check first column, last column are all 1.
	i = 0;
	last = game->columns - 1;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][last] != '1')
			error_n_exit("Error: incomplete walls.\n", game);
		i++;
	}
}

void	set_characters(t_map *game, int x, int y)
{
	if (game->map[x][y] == 'C')
			game->collectibles++;
	else if (game->map[x][y] == 'E')
	{
		if (game->exit != 0)
			error_n_exit("Error: too many exits.\n", game);
		game->exit = 1;
	}
	else if (game->map[x][y] == 'P')
	{
		if (game->players != 0)
			error_n_exit("Error: too many players.\n", game);
		game->players = 1;
		game->player.x = x;
		game->player.y = y;
	}
	//need to check that at least one exit, collectible, and 1 player.
}

void	check_characters(t_map *game)
{
	int x;
	int y;

	x = 0;
	game->exit = 0;
	game->collectibles = 0;
	game->players = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->columns)
		{
			if (game->map[x][y] == 'C' || game->map[x][y] == 'E' || game->map[x][y] == 'P')
				set_characters(game, x, y);
			else if (game->map[x][y] != '0' && game->map[x][y] != '1')
				error_n_exit("Error: invalid characters.\n", game);
			y++;
		}
		x++;
	}
	if (game->players != 1 || game->collectibles < 1 || game->exit != 1)
		error_n_exit("Error: not enough characters.\n", game);
	//ft_printf("player location = x: %d, y: %d\n", game->player.x, game->player.y);//REMOVE
}
