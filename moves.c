/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:18:02 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/11 11:23:45 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

// void	load_monkey(t_map *game, char dir)
// {
// 	if (mlx_image_to_window(game->mlx_ptr, game->img->grass, 
// 				game->player.x * PIXELS, game->player.y * PIXELS) < 0)
// 		error_n_exit("Failed to put image to window\n", game);
// 	if (dir == 'u')
// 	{
// 		game->player.y -= 1;
// 		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
// 				game->player.x * PIXELS, game->player.y * PIXELS) < 0)
// 			error_n_exit("Failed to put image to window\n", game);
// 	}
// 	if (dir == 'd')
// 	{
// 		game->player.y +=1;
// 		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
// 			game->player.x * PIXELS, game->player.y * PIXELS) < 0)
// 			error_n_exit("Failed to put image to window\n", game);
// 	}
// 	if (dir == 'r')
// 	{
// 		game->player.x +=1;
// 		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
// 			game->player.x * PIXELS, game->player.y * PIXELS) < 0)
// 			error_n_exit("Failed to put image to window\n", game);
// 	}	
// 	if (dir == 'l')
// 		{
// 		game->player.x -=1;
// 		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
// 			game->player.x * PIXELS, game->player.y * PIXELS) < 0)
// 			error_n_exit("Failed to put image to window\n", game);
// 	}	
// }

void	move_select(t_map *game, char line, char dir)
{
	ft_prinntf("move select");
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	move_player(t_map *game, char line, char dir)
{
	ft_prinntf("move player");
	move_select(game, line, dir);
	// load_monkey(game, dir);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_map	*game;

	game = (t_map *)data;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx_ptr);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}
