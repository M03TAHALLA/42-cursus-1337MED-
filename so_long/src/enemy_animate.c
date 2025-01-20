/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:20:58 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/19 15:08:08 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_enemy_textures(t_game *game)
{
	int	width;
	int	height;
	int	i;

	game->enemy_textures[0] = mlx_xpm_file_to_image(game->mlx, 
			"textures/enemy.xpm", &width, &height);
	game->enemy_textures[1] = mlx_xpm_file_to_image(game->mlx, 
			"textures/enemy1.xpm", &width, &height);
	game->enemy_textures[2] = mlx_xpm_file_to_image(game->mlx, 
			"textures/enemy2.xpm", &width, &height);
	game->enemy_textures[3] = mlx_xpm_file_to_image(game->mlx, 
			"textures/enemy3.xpm", &width, &height);
	i = 0;
	while (i < ENEMY_FRAME_COUNT)
	{
		if (!game->enemy_textures[i])
		{
			perror("Error loading enemy texture");
			free_map(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	animate_enemy(t_game *game)
{
	static int	frame = 0;
	static int	animation_frame = 0;

	if (frame % ANIMATION_SPEED == 0)
	{
		game->enemy = game->enemy_textures[animation_frame];
		animation_frame = (animation_frame + 1) % ENEMY_FRAME_COUNT;
		render_map(game);
	}
	frame++;
	return (0);
}
