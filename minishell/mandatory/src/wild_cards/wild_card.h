/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:36:50 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/17 23:43:03 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILD_CARD_H
# define WILD_CARD_H

# include <dirent.h>

char	**wild_cards(char *card);
int		check_wild_card(char *str, char *card);
int		letters_before_expand(const char *str, char c);

#endif