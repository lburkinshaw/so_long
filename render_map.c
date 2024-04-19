/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:36:07 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 13:28:09 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	select_img(t_map *game, int y, int x)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit_array("Error: image to window\n", game, game->map);
	}
	if (game->map[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->banana,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit_array("Error: image to window\n", game, game->map);
	}
	if (game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit_array("Error: image to window\n", game, game->map);
		set_exit_pos(game, x, y);
	}
	if (game->map[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit_array("Error: image to window\n", game, game->map);
	}
}

static void	fill_background(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (mlx_image_to_window(game->mlx_ptr, game->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				error_n_exit_array("Error: image to window\n", game, game->map);
			x++;
		}
		y++;
	}
}

static void	add_walls_exit(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == '1')
				select_img(game, y, x);
			x++;
		}
		y++;
	}
}

static void	add_player_collectibles(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P' || game->map[y][x] == 'C')
				select_img(game, y, x);
			x++;
		}
		y++;
	}
}

void	render_map(t_map *game)
{
	fill_background(game);
	add_walls_exit(game);
	add_player_collectibles(game);
}
