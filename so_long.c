/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:52 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/15 12:21:38 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>//remove or add to .h file?

int	row_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')//not counting newline that is at end of each line except last
		i++;
	return (i);
}

void	append_row(t_map *map, char *line, int len)
{
	int i;

	i = 0;

	map->map[map->rows] = malloc(sizeof(char) * len +1);
	while (line[i] && i < len + 1)
	{
		map->map[map->rows][i] = line[i];
		i++;
	}
	map->map[map->rows][i] = '\0';
}

void check_n_init_map(t_map *map, char *arg)
{
	//char	*map_temp;
	char	*line;
	int		fd;
	int		max_len;
	int		len;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		//error message "map could not be opened", exit.
	}
	/* CHECK THAT MAP SIZE IS VALID */
	//but i prob want to store this in a 2d array eventually??	
	max_len = 0;
	map->rows = 0;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = row_len(line);
		if (max_len == 0)
			max_len = len;
		//ft_printf("len = %d, max len = %d\n", len, max_len);
		if (max_len != 0 && len != max_len && !(len == 1 && line[0] == '\n'))
		{
			write(2, "Invalid size.\n", 12);
			free(line);
		//	close(fd);
			exit (1);
		}
		//ft_printf("%s\n", line);
		append_row(map, line, len);
		free(line);
		map->rows++;
	}
	ft_printf("Valid size\n");
	map->columns = max_len;
	/* init 2d array for map */
}

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
	
	
	return (0);	
}