/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:25:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/25 11:31:22 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_game(t_map *game)
{
	if (game->map)
		free_array(game->map);
	// if (game->collectibles)
	// 	game->collectibles = 0;
	// if (game->exit)
	// 	game->exit = 0;
	// if (game->players)
	// 	game->players = 0;
	free(game);
}

void	error_n_exit(char *msg, t_map *game)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		write(2, "Error\n", 6);
	free(game);
	exit(1);
}

