/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:19 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:35 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	skip_separator(char const **s, char sep, int *in_quotes)
{
	while (**s != '\0' && (**s == sep && !(*in_quotes)))
		(*s)++;
}

void	skip_word(char const **s, char sep, int *in_quotes)
{
	while (**s != '\0' && (**s != sep || *in_quotes))
	{
		if (**s == '\'')
			*in_quotes = !(*in_quotes);
		(*s)++;
	}
}
