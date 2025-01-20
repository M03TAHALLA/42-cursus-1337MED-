/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:46:08 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/19 11:15:28 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	valid_walls(char *line, int line_num)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_printf("Error\nInvalid Walls %d\n", line_num);
			free(line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_line(char *line, t_game *game, int line_num, int length)
{
	if (line == NULL)
	{
		line = malloc(length + 1);
		if (!line)
		{
			ft_printf("Error malloc");
			free_map(game);
			exit(EXIT_FAILURE);
		}
	}
	ft_strcpyline(line, game, line_num);
	valid_walls(line, line_num);
	if (ft_strlen(line) != length)
	{
		ft_printf("Incomplete Line %d\n", line_num);
		free(line);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	free(line);
}

static void	check_map_conditions(t_game *game)
{
	if (game->collectibles_count <= 0 || game->exit_count != 1 
		|| game->player_count != 1)
	{
		ft_printf("Error \nInvalid Map\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_game *game)
{
	check_map_conditions(game);
	check_line(NULL, game, 1, game->map_width);
	check_line(NULL, game, 2, game->map_width);
	check_line(NULL, game, 3, game->map_height);
	check_line(NULL, game, 4, game->map_height);
}

void	validate_map_checker(t_game *game)
{
	int	length;
	int	i;

	i = 1;
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	if (game->map_height == 0 || !game->map[0])
	{
		ft_printf("Error\nEmpty map or invalid map content\n");
		exit(EXIT_FAILURE);
	}
	game->map_width = ft_strlen(game->map[0]);
	length = ft_strlen(game->map[0]);
	while (i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != length 
			|| game->map_height != game->counter_line)
		{
			ft_printf("Error\nLine Not Equal\n");
			free_map(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
