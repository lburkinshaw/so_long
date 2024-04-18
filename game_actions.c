/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:29:05 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 17:19:12 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_map *game)
{
	ft_printf("Moves: %d\n", game->steps);
}

void	check_game_status(t_map *game, bool moved)
{
	if (moved == true)
		print_moves(game);
	if (game->collected == game->collectibles)
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_open,
				game->exit_pos.x * PIXELS, game->exit_pos.y * PIXELS) < 0)
			error_message("Failed to put image to window");
		game->img->exit_closed->instances->enabled = false;
		game->map[game->exit_pos.y][game->exit_pos.x] = '0';
		if (game->player.x == game->exit_pos.x \
			&& game->player.y == game->exit_pos.y)
		{
			ft_printf("🍌 Congratulations! 🍌\n");
			ft_printf("🍌 You made it through the portal with\n");
			ft_printf("🍌 all the bananas for your journey! 🍌\n");
			mlx_close_window(game->mlx_ptr);
		}
	}
}

void	remove_banana(t_map *game, int y, int x)
{
	int	i;

	i = 0;
	x = x * PIXELS;
	y = y * PIXELS;
	while (i < game->collectibles)
	{
		if (game->img->banana->instances[i].x == x
			&& game->img->banana->instances[i].y == y)
		{
			game->img->banana->instances[i].enabled = false;
		}
		i++;
	}
}
