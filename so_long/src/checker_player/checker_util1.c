/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:32:48 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/15 11:31:55 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	**initialize_visited(int height, int width)
{
	bool	**visited;
	int		i;

	visited = malloc(height * sizeof(bool *));
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(bool));
		i++;
	}
	return (visited);
}

void	process_current_cell(t_game_data *data, int x, int y)
{
	if (data->game->map[y][x] == 'C')
		data->collectibles_found++;
	if (data->game->map[y][x] == 'E')
		data->exit_found++;
}

void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	initialize_queue(t_game_data *data, int start_x, int start_y)
{
	data->queue[data->rear][0] = start_x;
	data->queue[data->rear][1] = start_y;
	data->rear++;
}

void	mark_visited(t_game_data *data, int x, int y)
{
	data->visited[y][x] = true;
}
