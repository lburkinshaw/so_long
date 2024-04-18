/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:49:46 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/18 16:47:27 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*file_to_str(t_map *game, char *arg)
{
	int		fd;
	char	*result;
	char	*line;
	char	*tmp;

	result = "\0";
	tmp = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_n_exit("Error: map could not be opened.\n", game);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(result, line);
		if (*result)
			free(result);
		result = (ft_strjoin(tmp, "\n"));
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	close(fd);
	return (result);
}

static void	check_characters(char *str, t_map *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n'
			&& str[i] != 'P' && str[i] != 'E' && str[i] != 'C')
			error_n_exit("Error: invalid characters\n", game);
		i++;
	}
	if (count_chars(str, 'P') != 1)
		error_n_exit("Error: invalid no. of players\n", game);
	else
		game->players = (count_chars(str, 'P'));
	if (count_chars(str, 'E') != 1)
		error_n_exit("Error: invalid no. of exits\n", game);
	else
		game->exit = (count_chars(str, 'E'));
	if (count_chars(str, 'C') < 1)
		error_n_exit("Error: invalid no. of collectibles\n", game);
	else
		game->collectibles = (count_chars(str, 'C'));
}

static void	set_game_values(t_map	*game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
			x++;
		if (game->columns == 0)
			game->columns = x;
		else if (x != game->columns)
		{
			free_array(game->map);
			error_n_exit("Error: invalid shape.\n", game);
		}
		y++;
	}
	if (game->rows == 0)
		game->rows = y;
	else if (x != game->rows)
		error_n_exit("Error: invalid shape.\n", game);
	if (game->rows > 23 || game->columns > 45)
		error_n_exit("Error: map too big\n", game);
}

static void	set_player_position(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->player.x = -1;
	game->player.y = -1;
	while (game->map[y] && game->player.x == -1 && game->player.y == -1)
	{
		x = 0;
		while (game->map[y][x] && game->player.x == -1 && game->player.y == -1)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	init_map(t_map *game, char *arg)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (len < 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0
		|| !arg[len - 5] || arg[len - 5] == '/')
		error_n_exit("Error: file type\n", game);
	str = NULL;
	str = file_to_str(game, arg);
	if (str[0] == '\0')
		error_n_exit("Error: empty map.\n", game);
	check_characters(str, game);
	game->map = ft_split(str, '\n');
	free(str);
	set_game_values(game);
	set_player_position(game);
	check_map(game);
}
