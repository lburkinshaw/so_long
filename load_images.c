/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:17 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/15 11:32:35 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_grass_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./images/grass.png");
	if (!grass)
	{
		error_message("Problem with loading png\n");
		return (NULL);
	}
	img->grass = mlx_texture_to_image(game->mlx_ptr, grass);
	if (!img->grass)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_wall_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./images/wall.png");
	img->wall = mlx_texture_to_image(game->mlx_ptr, wall);
	mlx_delete_texture(wall);
	if (!img->wall)
	{
		mlx_close_window(game->mlx_win);
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	return (img);
}

t_img	*load_monkey_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*monkey;

	monkey = mlx_load_png("./images/monkey_fwd.png");
	img->monkey = mlx_texture_to_image(game->mlx_ptr, monkey);
	mlx_delete_texture(monkey);
	if (!img->monkey)
	{
		mlx_close_window(game->mlx_win);
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	return (img);
}

t_img	*load_banana_texture(t_map *game, t_img *img)
{
	mlx_texture_t	*banana;

	banana = mlx_load_png("./images/banana.png");
	img->banana = mlx_texture_to_image(game->mlx_ptr, banana);
	mlx_delete_texture(banana);
	if (!img->banana)
	{
		mlx_close_window(game->mlx_win);
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	return (img);
}

t_img	*load_exit_closed(t_map *game, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/exit.png");
	img->exit_closed = mlx_texture_to_image(game->mlx_ptr, exit);
	mlx_delete_texture(exit);
	if (!img->exit_closed)
	{
		mlx_close_window(game->mlx_win);
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	return (img);
}

t_img	*load_exit_open(t_map *game, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/exit_open.png");
	img->exit_open = mlx_texture_to_image(game->mlx_ptr, exit);
	mlx_delete_texture(exit);
	if (!img->exit_open)
	{
		mlx_close_window(game->mlx_win);
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	return (img);
}

t_img	*init_images(t_map *game)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_grass_texture(game, assets);
	assets = load_wall_texture(game, assets);
	assets = load_banana_texture(game, assets);
	assets = load_monkey_texture(game, assets);
	assets = load_exit_closed(game, assets);
	assets = load_exit_open(game, assets);
	if (!assets->grass || !assets->wall || !assets->banana
		|| !assets->exit_open || !assets->exit_closed)//need to check this. could also do with a flag pointer. how can i free whole struct? 
	{
		free(assets);//need to free each bit inividually if/when malloced?? have i malloced?
		return (NULL);
	}
	return (assets);
}
