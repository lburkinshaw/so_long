/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:25:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 12:13:30 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_n_exit(char *msg, t_map *game)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		write(2, "Error\n", 6);
	free(game);
	exit(1);
}

