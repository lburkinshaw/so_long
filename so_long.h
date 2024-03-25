/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:28:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/25 12:11:16 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdlib.h> //for malloc?
# include <limits.h> //for max/min_int. check if necessary?
# include <unistd.h>
# include <fcntl.h>
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

typedef struct s_map
{
	char		**map;
	void		*object;
	int			columns; //x; 
	int			rows; //y;
	int			collectibles;
	int			exit;
	int			players;
	t_position	player;
}	t_map;

int		main(int argc, char **argv);
void	print_map(t_map *map); //remove before submit.
void	init_map(t_map *game, char *arg);
char	*file_to_str(t_map *game, char *arg);
void	check_map(t_map *game);
void	check_route(t_map *game);
void	flood_fill(char **map, t_position size, t_position begin, t_map *game);
int		count_chars(char *str, char c);
void	free_array(char **array);
void	free_game(t_map *game);
void	error_n_exit(char *msg, t_map *game);

#endif