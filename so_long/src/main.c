/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:34:47 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/11 10:34:47 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_game(t_game *game, char *map_path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->move_count = 0;
	game->score = 0;
	parse_map(game, map_path);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_path.ber>\n", argv[0]);
		return (1);
	}
	init_game(&game, argv[1]); 
	start_game(&game);
	return (0);
}
