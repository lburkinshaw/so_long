/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:56:29 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 13:28:39 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window(t_map *game)
{
	t_img	*images;

	game->mlx_ptr = mlx_init((game->columns) * PIXELS, (game->rows) * PIXELS, \
	"so_long", false);
	if (!game->mlx_ptr)
		error_n_exit_array("MLX error\n", game, game->map);
	images = init_images(game);
	if (!images)
		error_n_exit_array("MLX error\n", game, game->map);
	game->img = images;
}

void	run_mlx(t_map *game)
{
	init_window(game);
	render_map(game);
	mlx_key_hook(game->mlx_ptr, move_hook, game);
	mlx_loop(game->mlx_ptr);
	mlx_delete_image(game->mlx_ptr, game->img->banana);
	mlx_delete_image(game->mlx_ptr, game->img->wall);
	mlx_delete_image(game->mlx_ptr, game->img->grass);
	mlx_delete_image(game->mlx_ptr, game->img->monkey);
	mlx_delete_image(game->mlx_ptr, game->img->exit_closed);
	mlx_delete_image(game->mlx_ptr, game->img->exit_open);
	mlx_terminate(game->mlx_ptr);
}
