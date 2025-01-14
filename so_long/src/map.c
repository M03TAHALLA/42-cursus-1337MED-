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

static char	*read_map_file(const char *map_path)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	*temp;
	char	*old_line;

	fd = open(map_path, O_RDONLY);
	valid_map(fd, map_path);
	map_content = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error: Map file is empty");
		exit(EXIT_FAILURE);
	}
	old_line = line;
	while (line != NULL)
	{
		temp = map_content;
		map_content = ft_strjoin(map_content, line);
		if (!map_content)
			perror("Error while reading map file");
		line = ft_strtrim(line, "\n");
		valid_line_map(old_line, ft_strlen(line));
		line = get_next_line(fd);
	}
	close(fd);
	return (map_content);
}

static void	split_map(t_game *game, char *map_content)
{
	game->map = ft_split(map_content, '\n');
	if (!game->map)
		perror("Error splitting map content");
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
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
		ft_printf("or cannot collect all coins or reach the exit");
		exit(EXIT_FAILURE);
	}
}

void	parse_map(t_game *game, char *map_path)
{
	char	*map_content;

	map_content = read_map_file(map_path);
	split_map(game, map_content);
	validate_map(game);
	free(map_content);
}
