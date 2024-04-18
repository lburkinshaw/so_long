/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 16:28:41 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*move_up(t_map *game)
{
	bool	moved;

	moved = false;
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		if (game->map[game->player.y - 1][game->player.x] == 'C')
		{
			remove_banana(game, game->player.y - 1, game->player.x);
			game->map[game->player.y - 1][game->player.x] = '0';
			game->collected++;
		}
		game->player.y -= 1;
		game->img->monkey->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
		moved = true;
	}
	check_game_status(game, moved);
	return (game);
}

t_map	*move_down(t_map *game)
{
	bool	moved;

	moved = false;
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		if (game->map[game->player.y + 1][game->player.x] == 'C')
		{
			remove_banana(game, game->player.y + 1, game->player.x);
			game->map[game->player.y + 1][game->player.x] = '0';
			game->collected++;
		}
		game->player.y += 1;
		game->img->monkey->instances[0].y += 1 * PIXELS;
		game->steps += 1;
		moved = true;
	}
	check_game_status(game, moved);
	return (game);
}

t_map	*move_right(t_map *game)
{
	bool	moved;

	moved = false;
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		if (game->map[game->player.y][game->player.x + 1] == 'C')
		{
			remove_banana(game, game->player.y, game->player.x + 1);
			game->map[game->player.y][game->player.x + 1] = '0';
			game->collected++;
		}
		game->player.x += 1;
		game->img->monkey->instances[0].x += 1 * PIXELS;
		game->steps += 1;
		moved = true;
	}
	check_game_status(game, moved);
	return (game);
}

t_map	*move_left(t_map *game)
{
	bool	moved;

	moved = false;
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		if (game->map[game->player.y][game->player.x - 1] == 'C')
		{
			remove_banana(game, game->player.y, game->player.x - 1);
			game->map[game->player.y][game->player.x - 1] = '0';
			game->collected++;
		}
		game->player.x -= 1;
		game->img->monkey->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
		moved = true;
	}
	check_game_status(game, moved);
	return (game);
}
