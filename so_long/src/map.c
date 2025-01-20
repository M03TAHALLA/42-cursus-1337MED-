/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:05 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:47:14 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*read_map_file(const char *map_path, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	*temp;
	int		counter;

	counter = 0;
	fd = open(map_path, O_RDONLY);
	valid_map(fd, map_path);
	map_content = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
		exit_game(4, game);
	while (line != NULL)
	{
		temp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(temp);
		if (!map_content)
			perror("Error while reading map file\n");
		free(line);
		line = get_next_line(fd);
		counter++;
	}
	return (game->counter_line = counter, close(fd), map_content);
}

static void	split_map(t_game *game, char *map_content)
{
	game->map = ft_split(map_content, '\n');
	if (!game->map)
	{
		perror("Error splitting map content");
		free(map_content);
		exit(EXIT_FAILURE);
	}
	free(map_content);
	validate_map_checker(game);
}

static void	count_map_elements(t_game *game, int *player_found, 
	int *collectibles_found, int *exit_found)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				(*player_found)++;
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'E')
				(*exit_found)++;
			if (game->map[i][j] == 'C')
				(*collectibles_found)++;
		}
	}
}

static void	validate_map(t_game *game)
{
	int	player_found;
	int	collectibles_found;
	int	exit_found;

	player_found = 0;
	collectibles_found = 0;
	exit_found = 0;
	count_map_elements(game, &player_found, &collectibles_found, &exit_found);
	game->collectibles_count = collectibles_found;
	game->exit_count = exit_found;
	game->player_count = player_found;
	check_map(game);
	rectangle_map(game);
	if (!bfs_check(game))
	{
		ft_printf("Error\nPalyer is stuck ");
		ft_printf("or cannot collect all coins or reach the exit\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

void	parse_map(t_game *game, char *map_path)
{
	char	*map_content;

	map_content = read_map_file(map_path, game);
	split_map(game, map_content);
	validate_map(game);
}
