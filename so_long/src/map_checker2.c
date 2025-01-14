/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:01:48 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/13 17:21:45 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	file_name(const char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i] != '.')
		i++;
	++i;
	if (map_path[i] == 'b' && map_path[i + 1] == 'e' && map_path[i + 2] == 'r')
		return (1);
	else
		return (0);
}

void	rectangle_map(t_game *game)
{
	if (game->map_height == game->map_width)
	{
		ft_printf("Error \nNot Rectangle Map");
		exit(EXIT_FAILURE);
	}
}

void	valid_map(int fd, const char *map_path)
{
	if (fd < 0)
	{
		ft_printf("Error \nInvalid Path ");
		exit(EXIT_FAILURE);
	}
	if (file_name(map_path) == 0)
	{
		ft_printf("Error \nInvalid Name ");
		exit(EXIT_FAILURE);
	}
}

void	valid_line_map(char *line, int lenght)
{
	int	lenght_line;

	line = ft_strtrim(line, "\n");
	lenght_line = ft_strlen(line);
	if (lenght_line != lenght)
	{
		ft_printf("Error \nLine Not Equal");
		exit(EXIT_FAILURE);
	}
}
