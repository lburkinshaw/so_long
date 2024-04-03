/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:25:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/03 11:41:37 by lburkins         ###   ########.fr       */
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
