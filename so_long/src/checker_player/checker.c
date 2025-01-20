/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:54:33 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/16 13:30:46 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	bfs_check(t_game *game)
{
	t_game_data	data;
	bool		result;

	ft_memset(&data, 0, sizeof(t_game_data));
	data.game = game;
	data.visited = initialize_visited(game->map_height, game->map_width);
	data.collectibles_found = 0;
	data.exit_found = 0;
	data.rear = 0;
	initialize_queue(&data, game->player_x, game->player_y);
	mark_visited(&data, game->player_x, game->player_y);
	result = bfs_main_loop(&data);
	free_visited(data.visited, game->map_height);
	return (result);
}
