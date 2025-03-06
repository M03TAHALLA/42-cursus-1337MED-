/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:22:23 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/01 13:53:43 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	skip_separator(char const **s, char sep, int *in_quotes)
{
	while (**s != '\0' && (**s == sep && !(*in_quotes)))
		(*s)++;
}

void	skip_word(char const **s, char sep, int *in_quotes)
{
	while (**s != '\0' && (**s != sep || *in_quotes))
	{
		if (**s == '\'' )
			*in_quotes = !(*in_quotes);
		(*s)++;
	}
}
