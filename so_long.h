/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:28:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/10 14:12:16 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h> //for malloc?
# include <limits.h> //for max/min_int. check if necessary?
# include <unistd.h>
# include <fcntl.h>

//# define BLOCK 50
# define PIXELS 32
//WILL ALSO NEED OTHER INCLUDES FOR MLX LIBRARY

/*  STRUCT HERE THAT WILL BE POPULATED WITH MAP DATA */
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

/*typedef struct s_map
{
	char		**full;
	int			rows;// y
	int			columns;// x
	int			collectibles;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;*/

typedef struct s_img
{
	mlx_image_t			*wall;
	mlx_image_t			*grass;
	mlx_image_t			*banana;
	mlx_image_t			*monkey;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
	mlx_image_t			*enemy;
	mlx_image_t			*moves_print;
	mlx_image_t			*moves_nbr;
	mlx_image_t			*banana_nbr;
	mlx_image_t			*banana_2;
}	t_img;

typedef struct s_map
{
	char		**map;
	void		*object;
	int			columns; //x; 
	int			rows; //y;
	int			collectibles;
	int			exit;
	int			players;
	int			collected;
	int			steps;
	t_position	player;
	t_position	exit_pos;
	mlx_t		*mlx_win;
	mlx_t		*mlx_ptr;
	mlx_image_t	*walls;// do i want this?
	mlx_texture_t	*monkey_up;
	mlx_texture_t	*monkey_down;
	mlx_texture_t	*monkey_left;
	mlx_texture_t	*monkey_right;
	t_img		*img;
}	t_map;

int		main(int argc, char **argv);
void	print_map(t_map *map); //remove before submit.
void	init_map(t_map *game, char *arg);
char	*file_to_str(t_map *game, char *arg);
void	check_map(t_map *game);
int		check_route(t_map *game);
void	flood_fill(char **map, t_position size, t_position begin, t_map *game);
int		count_chars(char *str, char c);
void	free_array(char **array);
void	free_game(t_map *game);

//errors
void	error_n_exit(char *msg, t_map *game);
void	error_message(char *msg);
//mlx
void	init_mlx_stuff(t_map *game);
t_img	*init_images(mlx_t *mlx); 
void	move_hook(mlx_key_data_t keydata, void *data);
t_map	*move_up(t_map *game);
t_map	*move_down(t_map *game);
t_map	*move_right(t_map *game);
t_map	*move_left(t_map *game);


//mlx_t	*init_window(t_data *data);

#endif