/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:43:16 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 14:51:41 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit_pos(t_map *game, int x, int y)
{
	game->exit_pos.x = x;
	game->exit_pos.y = y;
}

int	count_chars(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	set_struct_zero(t_map *game)
{
	game->map = NULL;
	game->columns = 0;
	game->rows = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->players = 0;
	game->collected = 0;
	game->steps = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->exit_pos.x = 0;
	game->exit_pos.y = 0;
}
