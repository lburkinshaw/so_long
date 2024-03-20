/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:49:46 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/20 12:13:35 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')//not counting newline that is at end of each line except last
		i++;
	return (i);
}

void	append_row(t_map *game, char *line, int len)
{
	int i;

	i = 0;
	game->map[game->rows] = malloc(sizeof(char) * len +1);
	while (line[i] && i < len + 1)
	{
		game->map[game->rows][i] = line[i];
		i++;
	}
	game->map[game->rows][i] = '\0';
}

void	file_to_array(int fd, t_map *game)
{
	char	*line;
	int		max_len;
	int		len;

	max_len = 0;
	game->rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = row_len(line);
		if (max_len == 0)
			max_len = len;
		if (max_len != 0 && len != max_len && !(len == 1 && line[0] == '\n'))
		{
			free(line);
			close(fd);
			error_n_exit("Error: invalid map shape.\n", game);
		}
		append_row(game, line, len);
		free(line);
		game->rows++;
	}
	game->columns = max_len;
}

void	check_n_init_map(t_map *game, char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		//error message "map could not be opened", exit.
	}
	file_to_array(fd, game);//adds to 2d array and checks it is rectangle.
	check_walls(game);
	check_characters(game);
	//check_route with floodfill
}