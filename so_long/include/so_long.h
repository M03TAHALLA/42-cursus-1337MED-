/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:11 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/10 16:59:11 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ENEMY_FRAME_COUNT 4
# define ANIMATION_SPEED 3000
# include "/Users/mtahalla/Desktop/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../LIBFT/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles_count;
	int		player_count;
	int		exit_count;
	int		move_count;
	void	*player;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*enemy;
	void	*enemy_textures[4];
	void	*collectibles;
	void	*score;
	void	*wall;
	void	*empty_space;
	void	*door;
	void	*exit;
	int		win_width;
	int		win_height;
	char	player_direction;
}	t_game;

void	parse_map(t_game *game, char *map_path);
void	start_game(t_game *game);
int		handle_input(int keycode, t_game *game);
void	render_map(t_game *game);
int		exit_game(int ex);
int		file_name(const char *map_path);
void	rectangle_map(t_game *game);
void	valid_map(int fd, const char *map_path);
void	check_map(t_game *game);
int		ft_strcpyline(char *dst, t_game *game, int line);
void	valid_line_map(char *line, int lenght);
int		ft_strcpyline(char *dst, t_game *game, int line);
void	load_enemy_textures(t_game *game);
int		animate_enemy(t_game *game);
bool	bfs_check(t_game *game);

#endif