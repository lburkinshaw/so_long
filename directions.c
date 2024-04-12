/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/12 13:23:56 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_map *game)
{
	ft_printf("Moves: %d\n", game->steps);
}

void	check_game_status(t_map *game)
{
	print_moves(game);
	if (game->collected == game->collectibles)
	{	//ft_printf("x: %d, y: %d\n", game->exit_pos.x, game->exit_pos.y);
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_open,
				game->exit_pos.x * PIXELS, game->exit_pos.y * PIXELS) < 0)
			error_message("Failed to put image to window");
		game->img->exit_closed->instances->enabled = false;//added to make closed exit disappear
		game->map[game->exit_pos.y][game->exit_pos.x] = '0';
		if (game->player.x == game->exit_pos.x && game->player.y == game->exit_pos.y)
		{
			// sleep(1); //removing this got rid of delay to exit.
			mlx_close_window(game->mlx_ptr);
			ft_printf("Congratulations!\n");
			ft_printf("You made it through the portal with\n");
			ft_printf("all the bananas for your journey! 🍌\n");
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
			// game->collected++;
		}
		i++;
	}
}

// void    remove_banana(t_map *game)
// {
//     int    i;

//     i = 0;
//     while (i < game->collectibles)
//     {
//         ft_printf("collected: %d\n", game->collected);
// 		ft_printf("player x: %d\n", game->player.x);
// 		ft_printf("player y: %d\n", game->player.y);
// 		ft_printf("collectible x: %d\n", game->img->banana->instances[i].x / 32);
// 		ft_printf("collectible y: %d\n", game->img->banana->instances[i].y / 32);
// 	    if (game->player.x == (game->img->banana->instances[i].x) / 32
//             && game->player.y == (game->img->banana->instances[i].y) / 32)
//         {
//             ft_printf("test\n");
// 			game->img->banana->instances[i].enabled = false;
//             game->collected++;
			
//         }
//         i++;
//     }
// }

t_map	*move_up(t_map *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1'
		&& game->map[game->player.y - 1][game->player.x] != 'E')
	{
		if (game->map[game->player.y - 1][game->player.x] == 'C')
		{
			remove_banana(game, game->player.y - 1, game->player.x);
			// print_bananas(game);
			game->map[game->player.y - 1][game->player.x] = '0';
			game->collected++;
		}
		game->player.y -= 1;
		game->img->monkey->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_map	*move_down(t_map *game)
{
	if (game->map[game->player.y + 1][game->player.x] != '1'
		&& game->map[game->player.y + 1][game->player.x] != 'E')
	{
		if (game->map[game->player.y + 1][game->player.x] == 'C')
		{
			remove_banana(game, game->player.y + 1, game->player.x);
			// print_rupees(game);
			game->map[game->player.y + 1][game->player.x] = '0';
			game->collected++;
		}
		game->player.y += 1;
		game->img->monkey->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_map	*move_right(t_map *game)
{
	if (game->map[game->player.y][game->player.x + 1] != '1'
		&& game->map[game->player.y][game->player.x + 1] != 'E')
	{
		if (game->map[game->player.y][game->player.x + 1] == 'C')
		{
			remove_banana(game, game->player.y, game->player.x + 1);
			// print_rupees(game);
			game->map[game->player.y][game->player.x + 1] = '0';
			game->collected++;
		}
		game->player.x += 1;
		game->img->monkey->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	 check_game_status(game);
	return (game);
}

t_map	*move_left(t_map *game)
{
	if (game->map[game->player.y][game->player.x - 1] != '1'
		&& game->map[game->player.y][game->player.x - 1] != 'E')
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
	}
	check_game_status(game);
	return (game);
}
