/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:25:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/15 11:55:46 by lburkins         ###   ########.fr       */
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
	/*else
		write(2, "Error\n", 6);*/ //doesnt seem like it would come up? always include min error msg.
	free(game);
	exit(1);
}
