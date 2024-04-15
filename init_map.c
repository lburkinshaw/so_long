/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:49:46 by lburkins          #+#    #+#             */
/*   Updated: 2024/04/15 11:29:59 by lburkins         ###   ########.fr       */
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
		// if (tmp)
		// 	free(tmp);
		tmp = ft_strjoin(result, line);
		if (*result)
			free(result);
		result = (ft_strjoin(tmp, "\n"));//adding in the \n fixed unexpected behaviour in large files.
		free(line);
		free(tmp);
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
	{
		game->players = (count_chars(str, 'P'));
		ft_printf("%d\n", game->players);
	}
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

// void check_characters(char *str, t_map *game) {
//     int i = 0;
//     int player_count = 0;
//     int exit_count = 0;
//     int collectible_count = 0;

//     while (str[i]) {
//         if (str[i] != '1' && str[i] != '0' && str[i] != '\n'
//             && str[i] != 'P' && str[i] != 'E' && str[i] != 'C') {
//             error_n_exit("Error: invalid characters\n", game);
//         }

//         if (str[i] == 'P') {
//             player_count++;
//         } else if (str[i] == 'E') {
//             exit_count++;
//         } else if (str[i] == 'C') {
//             collectible_count++;
//         }

//         i++;
//     }
// 	ft_printf("players: %d\nexits: %d\ncollectibles%d\n", player_count, exit_count, collectible_count);
//     if (player_count != 1) {
//         error_n_exit("Error: invalid number of players\n", game);
//     } else {
//         game->players = player_count;
//     }

//     if (exit_count != 1) {
//         error_n_exit("Error: invalid number of exits\n", game);
//     } else {
//         game->exit = exit_count;
//     }

//     if (collectible_count < 1) {
//         error_n_exit("Error: invalid number of collectibles\n", game);
//     } else {
//         game->collectibles = collectible_count;
//     }

//     ft_printf("Characters OK.\n");
// }

void	set_game_values(t_map	*game)
{
	game->columns = 0;
	game->rows = 0;
	int y;
	int x;

	y= 0;//rows(vertical)
	x = 0; //columns(across)
	while (game->map[y])
	{
		while (game->map[y][x])
			x++;
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
	// ft_printf("columns = %d\n", game->columns);
	// ft_printf("rows = %d\n", game->rows);
}

void	set_player_position(t_map *game)
{
	int	y;
	int	x;

	y = 0;//rows(vertical)
	x = 0;//columns(across)
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
	int		len;

	len = ft_strlen(arg);
	if (len < 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0)
		error_n_exit("file error\n", game);
	str = NULL;
	str = file_to_str(game, arg);
	if (str[0] == '\0')
		error_n_exit("Error. Empty map.\n", game);
	ft_printf("String is:\n%s\n", str);
	check_characters(str, game);
	game->map = ft_split(str, '\n');
	free(str);
	set_game_values(game);
	set_player_position(game);
	check_map(game);
	print_map(game);//DELETE
}
