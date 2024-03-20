/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:52 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 11:26:10 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_map *map)
{
	int i = 0;
	while (i < map->rows)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

int	main (int argc, char **argv)
{
	t_map *game;
	
	game = malloc(sizeof(t_map));
	if (!game)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	check_n_init_map(game, argv[1]);
	print_map(game);
	free(game);
	ft_printf("finished\n");//REMOVE
	return (0);
}