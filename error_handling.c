/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:25:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/19 12:18:47 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_n_exit_array(char *msg, t_map *game, char **array)
{
	free_array(array);
	error_n_exit(msg, game);
}

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
	if (game->img)
		free(game->img);
	free(game);
}

void	error_message(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	error_n_exit(char *msg, t_map *game)
{
	if (msg)
		error_message(msg);
	free(game);
	exit(1);
}
