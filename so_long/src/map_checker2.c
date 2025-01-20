/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:01:48 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/19 10:54:34 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_split(char **split, int ex)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (ex == 6)
		exit_game(ex, NULL);
}

int	file_name(const char *map_path)
{
	int		i;
	char	**base_name;
	int		count;

	i = 0;
	count = 0;
	base_name = ft_split(map_path, '/');
	if (!base_name)
		return (0);
	while (base_name[count] != 0)
		count++ ;
	if (count != 3)
		free_split(base_name, 6);
	if (ft_strlen(base_name[2]) <= 4)
		return (free_split(base_name, 5), 0);
	while (map_path[i] != '.')
		i++;
	++i;
	if (map_path[i] == 'b' && map_path[i + 1] == 'e' && map_path[i + 2] == 'r'
		&& map_path[i + 3] == '\0')
		return (free_split(base_name, 5), 1);
	else
		return (free_split(base_name, 5), 0);
}

void	rectangle_map(t_game *game)
{
	if (game->map_height == game->map_width)
	{
		ft_printf("Error \nNot Rectangle Map\n");
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

void	valid_map(int fd, const char *map_path)
{
	if (fd < 0)
	{
		ft_printf("Error \nInvalid Path\n");
		exit(EXIT_FAILURE);
	}
	if (file_name(map_path) == 0)
	{
		ft_printf("Error \nInvalid Name\n");
		exit(EXIT_FAILURE);
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}
