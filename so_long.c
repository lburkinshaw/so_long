/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:52 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 16:55:46 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->player.x = 0;
	game->player.y = 0;
	game->exit_pos.x = 0;
	game->exit_pos.y = 0;
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (!game)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	set_struct_zero(game);
	init_map(game, argv[1]);
	run_mlx(game);
	free_game(game);
	return (0);
}
