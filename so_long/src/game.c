/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:05 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/15 20:47:14 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_player_textures(t_game *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlx, "textures/right.xpm",
			&width, &height);
	game->player_up = mlx_xpm_file_to_image(game->mlx, "textures/up.xpm",
			&width, &height);
	game->player_down = mlx_xpm_file_to_image(game->mlx, "textures/down.xpm",
			&width, &height);
	game->player_left = mlx_xpm_file_to_image(game->mlx, "textures/left.xpm",
			&width, &height);
	game->player_right = mlx_xpm_file_to_image(game->mlx, "textures/right.xpm",
			&width, &height);
	if (!game->player_up || !game->player_down || !game->player_left
		|| !game->player_right)
	{
		perror("Error loading player textures");
		exit(EXIT_FAILURE);
	}
}

static void	load_environment_textures(t_game *game)
{
	int	width;
	int	height;

	game->enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&width, &height);
	game->collectibles = mlx_xpm_file_to_image(game->mlx, "textures/coins.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->empty_space = mlx_xpm_file_to_image(game->mlx, "textures/space.xpm",
			&width, &height);
	game->door = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	if (!game->enemy || !game->collectibles || !game->wall || !game->empty_space
		|| !game->door || !game->exit)
	{
		perror("Error loading environment textures");
		exit(EXIT_FAILURE);
	}
}

static void	load_textures(t_game *game)
{
	load_player_textures(game);
	load_environment_textures(game);
	load_enemy_textures(game);
}

int	exit_game(int ex)
{
	if (ex == 1)
		ft_printf("Hhhhhhhhh Your Dead\n");
	else if (ex == 2)
		ft_printf("Nadi Rba7ti!\n");
	else 
		ft_printf("Game Over\n");
	exit(EXIT_SUCCESS);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, (game->map_width) * 52,
			game->map_height * 52 + 45, "So Long");
	if (!game->win)
	{
		perror("Error creating window");
		exit(EXIT_FAILURE);
	}
	load_textures(game);
	render_map(game);
	mlx_loop_hook(game->mlx, animate_enemy, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_loop(game->mlx);
}
