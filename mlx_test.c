/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:56:29 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/15 11:53:44 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include "MLX42/MLX42.h"//not necessary as included in so_long.h??


/*void	mlx_test(t_map	*game)
{
	game->mlx_ptr = mlx_init(game->columns, game->rows, "My Game", false);
	if (!game->mlx_ptr)
		error_n_exit("MLX error", game);
	game->mlx_win = mlx_new_window(game->mlx_ptr, 600, 400, "hi :)");
	if (!game->mlx_win)
	{
		free(game->mlx_ptr);
		error_n_exit("Window error", game);
	}
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	//init mlx
	//init window
	free(game->mlx_ptr);
}*/

/*void	init_walls(t_map *game)
{
	game->walls = ;
}*/

void	fill_background(t_map *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (mlx_image_to_window(game->mlx_ptr, game->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				error_n_exit("Failed to put image to window\n", game);// is this enough??
				//error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	init_window(t_map *game)
{
	t_img	*images;
	
	game->mlx_ptr = mlx_init((game->columns) * PIXELS, (game->rows) * PIXELS,
						"so_long", true);//could set to false //create function to set tile size instead of BLOCK?? 
	if (!game->mlx_ptr)
		error_n_exit("MLX error\n", game);
	images = init_images(game);//takes care of load_png and texture_to_image
	if (!images)
		error_n_exit("", game);//need to check
	game->img = images;
	fill_background(game);//takes care of img_to_window
	//mlx_load_png() -> malloc check //mlx_texture
	//mlx_texture_to_image + malloc check //delete texture / do this for all images and store in another "image" struct.
	//mlx_put_image_to_window
	//mlx_key_hook() // for movements.
	//ABOVE IS TO INITIALISE STRUCT.

}

void	select_img(t_map *game, int y, int x)
{
	if (game->map[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);//need to free anything else?
	}
	if (game->map[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->banana,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);//need to free anything else?
	}
	if (game->map[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->monkey,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);//need to free anything else?
	}
	if (game->map[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx_ptr, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_n_exit("Failed to put image to window\n", game);//need to free anything else?
			game->exit_pos.x = x;
			game->exit_pos.y = y;
	}
}

void	render_map(t_map *game)
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
			select_img(game, y, x);
			x++;
		}
		y++;
	}
}
// static void	load_monkey_textures(t_map *game)
// {
// 	game->monkey_up = mlx_load_png("./Images/monkey_back.png");
// 	if (!game->monkey_up)
// 		error_message("Problem with loading png");
// 	game->monkey_down = mlx_load_png("./Sprites/monkey_front.png");
// 	if (!game->monkey_down)
// 		error_message("Problem with loading png");
// 	game->monkey_left = mlx_load_png("./Sprites/monkey_left.png");
// 	if (!game->monkey_left)
// 		error_message("Problem with loading png");
// 	game->monkey_right = mlx_load_png("./Sprites/monkey_right.png");
// 	if (!game->monkey_right)
// 		error_message("Problem with loading png");
// }

void	init_mlx_stuff(t_map *game)
{
	// load_monkey_textures(game); //might not need this if not doing changing img direction
	init_window(game);
	render_map(game);
	//string_to_screen > prints moves?
//	init_walls(game);// sets image for walls/obstacles game->walls
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

