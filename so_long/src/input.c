/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:05 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:47:14 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (is_valid_move(game, new_x, new_y))
	{
		if (game->map[new_y][new_x] == 'X')
			exit_game(1, game);
		if (game->map[new_y][new_x] == 'C')
		{
			game->collectibles_count--;
			game->score += 10;
		}
		if (game->map[new_y][new_x] == 'E' && game->collectibles_count == 0)
			exit_game(2, game);
		if (game->map[new_y][new_x] == 'E' && game->collectibles_count != 0)
			ft_printf("Lbab Msdod Asahbi Zid jma3 Coins\n");
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_x = new_x;
			game->player_y = new_y;
			game->map[new_y][new_x] = 'P';
			game->move_count++;
			ft_printf("\033[H\033[J");
			ft_printf("Moves : %d\nScore : %d\n", game->move_count, game->score);
			render_map(game);
		}
	}
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(3, game);
	else if (keycode == 126)
	{
		game->player_direction = 'U';
		move_player(game, game->player_x, game->player_y - 1);
	}
	else if (keycode == 125)
	{
		game->player_direction = 'D';
		move_player(game, game->player_x, game->player_y + 1);
	}
	else if (keycode == 123)
	{
		game->player_direction = 'L';
		move_player(game, game->player_x - 1, game->player_y);
	}
	else if (keycode == 124)
	{
		game->player_direction = 'R';
		move_player(game, game->player_x + 1, game->player_y);
	}
	render_map(game);
	return (0);
}
