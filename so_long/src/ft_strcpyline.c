/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:32:54 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/16 19:09:40 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	copy_line(char *dst, t_game *game, int line, int *i)
{
	if (line == 1)
	{
		while (*i < game->map_width)
		{
			dst[*i] = game->map[0][*i];
			(*i)++;
		}
	}
	else if (line == 2)
	{
		while (*i < game->map_width)
		{
			dst[*i] = game->map[game->map_height - 1][*i];
			(*i)++;
		}
	}
}

static void	copy_column(char *dst, t_game *game, int line, int *i)
{
	if (line == 3)
	{
		while (*i < game->map_height)
		{
			dst[*i] = game->map[*i][0];
			(*i)++;
		}
	}
	else if (line == 4)
	{
		while (*i < game->map_height)
		{
			dst[*i] = game->map[*i][game->map_width - 1];
			(*i)++;
		}
	}
}

int	ft_strcpyline(char *dst, t_game *game, int line)
{
	int	i;

	i = 0;
	copy_line(dst, game, line, &i);
	copy_column(dst, game, line, &i);
	dst[i] = '\0';
	return (i);
}
