/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card_help_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:22:09 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/18 15:33:27 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	letters_before_expand(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	check_wild_card(char *str, char *card)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && card[j])
	{
		if (card[j] == '*')
		{
			if (card[j + 1] == '\0')
				return (1);
			else
				i += letters_before_expand(str + i, card[j++ + 1]);
			i += letters_before_expand(str + i, card[j + 1]);
			j++;
		}
		else if (str[i] == card[j])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	return (1);
}
