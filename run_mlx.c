/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:56:29 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 17:09:55 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_map *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (mlx_image_to_window(game->mlx_ptr, game->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				error_n_exit("Failed to put image to window\n", game);
			x++;
		}
		y++;
	}
}

void	init_window(t_map *game)
{
	t_img	*images;

	game->mlx_ptr = mlx_init((game->columns) * PIXELS, (game->rows) * PIXELS, \
	"so_long", true);
	if (!game->mlx_ptr)
		error_n_exit("MLX error\n", game);
	images = init_images(game);
	if (!images)
		error_n_exit("", game);
	game->img = images;
}

void	select_img(t_map *game, int y, int x)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);
	}
	if (game->map[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->banana,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);
	}
	if (game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);
		set_exit_pos(game, x, y);
	}
	if (game->map[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);
	}
}
void	add_walls_exit(t_map *game)
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


void	render_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	fill_background(game);
	add_walls_exit(game);
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
