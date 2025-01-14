/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:46:08 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/13 13:47:27 by mtahalla         ###   ########.fr       */
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
			ft_printf("Error\nInvalid Walls %d", line_num);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_line(char *line, t_game *game, int line_num,
	int expected_length)
{
	int	length;

	line = malloc(expected_length);
	ft_strcpyline(line, game, line_num);
	valid_walls(line, line_num);
	length = ft_strlen(line);
	if (length != expected_length)
	{
		printf("Incomplete Line %d", line_num);
		exit(EXIT_FAILURE);
	}
	free(line);
}

static void	check_map_conditions(t_game *game)
{
	if (game->collectibles_count <= 0 || game->exit_count != 1 
		|| game->player_count != 1)
	{
		ft_printf("Error \nInvalid Map ");
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
