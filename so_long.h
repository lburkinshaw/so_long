/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:28:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 12:14:52 by lburkins         ###   ########.fr       */
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
}	t_positon;

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
	t_positon	player;
}	t_map;

int		main(int argc, char **argv);
void	check_n_init_map(t_map *map, char *arg);
void	check_walls(t_map	*game);
void	check_characters(t_map *game);
void	error_n_exit(char *msg, t_map *game);

#endif