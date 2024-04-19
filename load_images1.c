/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:17 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 14:41:15 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_grass_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./images/grass.png");
	if (!grass)
	{
		error_message("Error loading png\n");
		return ;
	}
	img->grass = mlx_texture_to_image(game->mlx_ptr, grass);
	if (!img->grass)
	{
		error_message("Error with texture to image\n");
		return ;
	}
	mlx_delete_texture(grass);
}

static void	load_wall_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./images/wall.png");
	if (!wall)
	{
		error_message("Error loading png\n");
		return ;
	}
	img->wall = mlx_texture_to_image(game->mlx_ptr, wall);
	mlx_delete_texture(wall);
	if (!img->wall)
	{
		mlx_close_window(game->mlx_win);
		error_message("Error with texture to image\n");
		return ;
	}
}

static void	load_monkey_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*monkey;

	monkey = mlx_load_png("./images/monkey.png");
	if (!monkey)
	{
		error_message("Error loading png\n");
		return ;
	}
	img->monkey = mlx_texture_to_image(game->mlx_ptr, monkey);
	mlx_delete_texture(monkey);
	if (!img->monkey)
	{
		mlx_close_window(game->mlx_win);
		error_message("Error with texture to image\n");
		return ;
	}
}

static void	load_banana_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*banana;

	banana = mlx_load_png("./images/banana.png");
	if (!banana)
	{
		error_message("Error loading png\n");
		return ;
	}
	img->banana = mlx_texture_to_image(game->mlx_ptr, banana);
	mlx_delete_texture(banana);
	if (!img->banana)
	{
		mlx_close_window(game->mlx_win);
		error_message("Error with texture to image\n");
		return ;
	}
}

t_img	*init_images(t_map *game)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	load_grass_texture(game, assets);
	load_wall_texture(game, assets);
	load_banana_texture(game, assets);
	load_exit_closed(game, assets);
	load_exit_open(game, assets);
	load_monkey_texture(game, assets);
	if (!assets->grass || !assets->wall || !assets->banana
		|| !assets->exit_open || !assets->exit_closed || !assets->monkey)
	{
		free(assets);
		return (NULL);
	}
	return (assets);
}
