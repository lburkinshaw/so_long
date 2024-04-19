/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:28:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 14:53:26 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PIXELS 64

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_img
{
	mlx_image_t			*wall;
	mlx_image_t			*grass;
	mlx_image_t			*banana;
	mlx_image_t			*monkey;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			columns;
	int			rows;
	int			collectibles;
	int			exit;
	int			players;
	int			collected;
	int			steps;
	t_position	player_pos;
	t_position	exit_pos;
	mlx_t		*mlx_win;
	mlx_t		*mlx_ptr;
	t_img		*img;
}	t_map;

int		main(int argc, char **argv);
/* ****************** */
/******* PARSING ******/
/* ****************** */
void	set_struct_zero(t_map *game);
void	init_map(t_map *game, char *arg);
void	check_map(t_map *game);
int		check_route(t_map *game);
void	flood_fill(char **map, t_position size, t_position begin, t_map *game);
void	set_exit_pos(t_map *game, int x, int y);
int		count_chars(char *str, char c);
/* ****************** */
/*** ERROR AND FREE ***/
/* ****************** */
void	free_array(char **array);
void	free_game(t_map *game);
void	error_n_exit(char *msg, t_map *game);
void	error_n_exit_array(char *msg, t_map *game, char **array);
void	error_message(char *msg);
/* ****************** */
/******** MLX *********/
/* ****************** */
void	run_mlx(t_map *game);
t_img	*init_images(t_map *game);
t_img	*load_exit_closed(t_map *game, t_img	*img);
t_img	*load_exit_open(t_map *game, t_img *img);
void	render_map(t_map *game);
void	move_hook(mlx_key_data_t keydata, void *data);
void	move_up(t_map *game);
void	move_down(t_map *game);
void	move_right(t_map *game);
void	move_left(t_map *game);
void	check_game_status(t_map *game, bool moved);
void	remove_banana(t_map *game, int y, int x);

#endif