/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:52 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 10:59:53 by lburkins         ###   ########.fr       */
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
	t_map *map;
	
	map = malloc(sizeof(t_map));

	//check_args(argc, argv);
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	check_n_init_map(map, argv[1]);
	print_map(map);
	ft_printf("finished\n");//REMOVE
	return (0);
}