/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:17 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/11 11:30:06 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	ft_printf("test grass\n");
	mlx_texture_t	*grass;

	grass = mlx_load_png("./images/grass.png");
	if (!grass)
	{
		error_message("Problem with loading png\n");
		return (NULL);
	}
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture (grass);
	return (img);
}

t_img	*load_wall_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*wall;

	ft_printf("test wall\n");
	wall = mlx_load_png("./images/wall.png");
	if (!wall)
	{
		error_message("Problem with loading png\n");//mlx_close_window(game->mlx_win)??
		return (NULL);
	}
	img->wall = mlx_texture_to_image(mlx, wall);
	if (!img->wall)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture (wall);
	return (img);
}

t_img	*load_monkey_texture(mlx_t *mlx, t_img *img)
{
	ft_printf("test monkey\n");
	mlx_texture_t	*monkey;

	monkey = mlx_load_png("./images/monkey_fwd.png");
	if (!monkey)
	{
		error_message("Problem with loading png\n");
		return (NULL);
	}
	img->monkey = mlx_texture_to_image(mlx, monkey);
	if (!img->monkey)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture (monkey);
	return (img);
}

t_img	*load_banana_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*banana;

	ft_printf("test banana\n");
	banana = mlx_load_png("./images/banana.png");
	if (!banana)
		error_message("Problem with loading png\n");
	img->banana = mlx_texture_to_image(mlx, banana);
	if (!img->banana)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture(banana);
	return (img);
}

t_img	*load_exit_closed(mlx_t *mlx, t_img	*img)
{
	mlx_texture_t	*exit;

	ft_printf("test exit\n");
	exit = mlx_load_png("./images/exit.png");
	if (!exit)
	{
		error_message("Problem with loading png\n");
		return (NULL);
	}
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture(exit);
	return (img);
}

t_img	*load_exit_open(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	ft_printf("test wall\n");
	exit = mlx_load_png("./images/exit_open.png");
	if (!exit)
	{
		error_message("Problem with loading png\n");
		return (NULL);
	}
	img->exit_open = mlx_texture_to_image(mlx, exit);
	if (!img->exit_open)
	{
		error_message("Problem with texture to image\n");
		return (NULL);
	}
	mlx_delete_texture(exit);
	return (img);
}

t_img	*init_images(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_grass_texture(mlx, assets);
	assets = load_wall_texture(mlx, assets);
	assets = load_banana_texture(mlx, assets);
	assets = load_monkey_texture(mlx, assets);
	assets = load_exit_closed(mlx, assets);
	assets = load_exit_open(mlx, assets);
	if (!assets->grass || !assets->wall || !assets->banana
		|| !assets->exit_open || !assets->exit_closed)//need to check this. could also do with a flag pointer. how can i free whole struct? 
	{
		free(assets);//need to free each bit inividually if/when malloced?? have i malloced?
		return (NULL);
	}
	return (assets);
}
