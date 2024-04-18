/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:19:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 16:44:16 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_map	*game)
{
	int	i;
	int	last;

	i = 0;
	last = game->rows - 1;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[last][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	last = game->columns - 1;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][last] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_map *game)
{
	if (check_walls(game) == 1)
	{
		if (game->map)
			free_array(game->map);
		error_n_exit("Error: incomplete walls\n", game);
	}
	if (check_route(game) == 1)
	{
		if (game->map)
			free_array(game->map);
		error_n_exit("Error: invalid route\n", game);
	}
}
