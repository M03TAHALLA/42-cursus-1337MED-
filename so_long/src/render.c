/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:05 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:47:14 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_tile(t_game *game, int x, int y, void *image)
{
	mlx_put_image_to_window(game->mlx, game->win, image, 
		x * 52, (y * 52) + 45);
}

static void	render_player(t_game *game, int x, int y)
{
	if (game->player_direction == 'U')
	{
		game->player = game->player_up;
		render_tile(game, x, y, game->player);
	}
	else if (game->player_direction == 'D')
	{
		game->player = game->player_down;
		render_tile(game, x, y, game->player);
	}
	else if (game->player_direction == 'L')
	{
		game->player = game->player_left;
		render_tile(game, x, y, game->player);
	}
	else if (game->player_direction == 'R')
	{
		game->player = game->player_right;
		render_tile(game, x, y, game->player);
	}
	else
		render_tile(game, x, y, game->player);
}

static void	render_environment(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		render_tile(game, x, y, game->wall);
	else if (game->map[y][x] == '0')
		render_tile(game, x, y, game->empty_space);
	else if (game->map[y][x] == 'C')
		render_tile(game, x, y, game->collectibles);
	else if (game->map[y][x] == 'X')
		render_tile(game, x, y, game->enemy);
	else if (game->map[y][x] == 'E')
	{
		if (game->collectibles_count == 0)
			render_tile(game, x, y, game->exit);
		else
			render_tile(game, x, y, game->door);
	}
}

static void	score_bar(t_game *game)
{
	char	*moves_str;
	char	*score_str;
	char	*full_str;
	int		moves_x;
	int		score_x;

	moves_str = ft_itoa((int)game->move_count);
	full_str = ft_strjoin("Moves: ", moves_str);
	moves_x = (game->map_width * 52 - (ft_strlen(full_str) * 10)) / 2;
	mlx_string_put(game->mlx, game->win, moves_x, 15, 0xFFFFFF, full_str);
	score_str = ft_itoa((int)game->score);
	full_str = ft_strjoin("Score: ", score_str);
	score_x = (game->map_width * 52 - (ft_strlen(full_str) * 10)) / 2;
	mlx_string_put(game->mlx, game->win, score_x, 35, 0xFFFFFF, full_str);
	free(moves_str);
	free(score_str);
	free(full_str);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(game->mlx, game->win);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				render_player(game, x, y);
			else
				render_environment(game, x, y);
			x++;
		}
		y++;
	}
	score_bar(game);
}
