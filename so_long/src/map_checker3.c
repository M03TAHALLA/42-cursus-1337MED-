/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:54:33 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/14 16:19:30 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	is_valid_move(t_game *game, int x, int y, bool **visited)
{
	return (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height &&
		game->map[y][x] != '1' && game->map[y][x] != 'X' && !visited[y][x]);
}

bool	bfs_check(t_game *game)
{
	int		dx[4] = {1, -1, 0, 0};
	int		dy[4] = {0, 0, 1, -1};
	bool	**visited;
	int		collectibles_found = 0;
	int		exit_found = 0;
	int		queue[game->map_height * game->map_width][2];
	int		front = 0;
	int		rear = 0;
	int		i;

	visited = malloc(game->map_height * sizeof(bool *));
	i = 0;
	while (i < game->map_height)
	{
		visited[i] = malloc(game->map_width * sizeof(bool));
		i++;
	}
	queue[rear][0] = game->player_x;
	queue[rear++][1] = game->player_y;
	visited[game->player_y][game->player_x] = true;

	while (front < rear)
	{
		int x = queue[front][0];
		int y = queue[front++][1];

		if (game->map[y][x] == 'C')
			collectibles_found++;
		if (game->map[y][x] == 'E')
			exit_found++;
		i = 0;
		while (i < 4)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (is_valid_move(game, new_x, new_y, visited))
			{
				queue[rear][0] = new_x;
				queue[rear++][1] = new_y;
				visited[new_y][new_x] = true;
			}
			i++;
		}
	}
	i = 0;
	while(i < game->map_height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);

	return (collectibles_found == game->collectibles_count && exit_found > 0);
}
