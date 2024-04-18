/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:47:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:02 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_exit_closed(t_map *game, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./images/exit.png");
	if (!exit)
	{
		error_message("Error loading png\n");
		return (NULL);
	}
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
	if (!exit)
	{
		error_message("Error loading png\n");
		return (NULL);
	}
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
