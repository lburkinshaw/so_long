/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:52 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 14:51:31 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*game;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	game = malloc(sizeof(t_map));
	if (!game)
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
