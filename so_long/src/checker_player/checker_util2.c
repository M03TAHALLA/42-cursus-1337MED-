/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:32:52 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/16 10:32:31 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	is_valid_move(t_game *game, int x, int y, bool **visited)
{
	return (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height
		&& game->map[y][x] != '1' && game->map[y][x] != 'X' && !visited[y][x]);
}

static void	initialize_directions(int dx[4], int dy[4])
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}

void	add_neighboring_cells(t_game_data *data, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	new_x;
	int	new_y;
	int	i;

	initialize_directions(dx, dy);
	i = 0;
	while (i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (is_valid_move(data->game, new_x, new_y, data->visited))
		{
			data->queue[data->rear][0] = new_x;
			data->queue[data->rear][1] = new_y;
			data->rear++;
			mark_visited(data, new_x, new_y);
		}
		i++;
	}
}

bool	bfs_main_loop(t_game_data *data)
{
	int	front;
	int	x;
	int	y;

	front = 0;
	while (front < data->rear)
	{
		x = data->queue[front][0];
		y = data->queue[front][1];
		front++;
		if (data->game->map[y][x] == 'E')
		{
			data->exit_found++;
			continue ;
		}
		process_current_cell(data, x, y);
		add_neighboring_cells(data, x, y);
	}
	return (data->collectibles_found == data->game->collectibles_count 
		&& data->exit_found > 0);
}
