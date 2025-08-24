/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:40:05 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/28 18:49:14 by mtahalla         ###   ########.fr       */
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
	if (!s || !*s || !**s)
		return ;
	while (**s != '\0')
	{
		if (**s == '\'' || **s == '\"')
			*in_quotes = !(*in_quotes);
		if (**s == sep && !*in_quotes)
			break ;
		(*s)++;
	}
}

char	**free_split_args(char **strings, int i)
{
	while (i > 0)
	{
		i--;
		free(strings[i]);
	}
	free(strings);
	return (NULL);
}

char	**allocate_strings(char const *s, char c)
{
	char	**strings;

	if (s[0] == '\0')
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	return (strings);
}

void	handle_quoted_string(const char **s, char **strings, int *i)
{
	char		quote;
	const char	*start;

	quote = **s;
	(*s)++;
	start = *s;
	while (**s != '\0' && **s != quote)
		(*s)++;
	if (**s == quote)
		strings[(*i)++] = ft_substr(start, 0, *s - start);
	(*s)++;
}
