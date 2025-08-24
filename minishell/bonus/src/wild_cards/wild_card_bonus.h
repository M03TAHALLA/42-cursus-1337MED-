/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:36:50 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/18 15:33:22 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILD_CARD_BONUS_H
# define WILD_CARD_BONUS_H

# include <dirent.h>

char	**wild_cards(char *card);
int		check_wild_card(char *str, char *card);
int		letters_before_expand(const char *str, char c);

#endif