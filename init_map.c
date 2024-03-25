/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:49:46 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/25 11:43:24 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_map *game)//remove before submit
{
	int	i = 0;
	ft_printf("Map is:\n");
	while (game->map[i] != '\0')
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}

char	*file_to_str(t_map *game, char *arg)
{
	int		fd;
	char	*result;
	char	*line;
	char	*tmp;

	result = "\0";
	line = NULL;
	tmp = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_n_exit("Error: map could not be opened.\n", game);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (tmp)
			free(tmp);
		tmp = ft_strjoin(result, line);
		result = tmp;
		free(line);
	}
	close(fd);
	return (result);
}

void	check_characters(char *str, t_map *game)
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
	ft_printf("Characters OK.\n");
}

void	set_game_values(t_map	*game)
{
	game->columns = 0;
	game->rows = 0;
	int y = 0;//rows(vertical)
	int x = 0; //columns(across)
	
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			/*below isnt working yet*/
			// if (game->map[y][x] == 'P')
			// {
			// 	game->player.y = y;
			// 	game->player.x = x;
			// }
			x++;
		}
		if (game->columns == 0)
			game->columns = x;
		else if (x != game->columns)
			error_n_exit("Error. Invalid shape.\n", game);
		y++;
	}
	if (game->rows == 0)
		game->rows = y;
	else if (x != game->rows)
		error_n_exit("Error. Invalid shape.\n", game);
	ft_printf("columns = %d\n", game->columns);
	ft_printf("rows = %d\n", game->rows);
}

void	set_player_position(t_map *game)
{
	int y = 0;//rows(vertical)
	int x = 0; //columns(across)
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
	ft_printf("player position: y=%d, x=%d\n", game->player.y, game->player.x);
}

void	init_map(t_map *game, char *arg)
{
	char	*str;

	str = NULL;
	str = file_to_str(game, arg);
	if (str[0] == '\0')
		error_n_exit("Error. Empty map.\n", game);
	check_characters(str, game);
	ft_printf("string is:\n%s\n", str);
	game->map = ft_split(str, '\n');
	free(str);
	set_game_values(game);
	set_player_position(game);
	check_map(game);
	print_map(game);
}
