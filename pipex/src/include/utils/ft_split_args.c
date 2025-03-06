/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:38:22 by mtahalla          #+#    #+#             */
/*   Updated: 2025/03/01 13:58:32 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	**free_split(char **strings, int i)
{
	while (i > 0)
	{
		i--;
		free(strings[i]);
	}
	free(strings);
	return (NULL);
}

static int	count_strings(char const *s, char sep)
{
	int	count;
	int	in_quotes;

	count = 0;
	in_quotes = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && (*s == sep && !in_quotes))
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && (*s != sep || in_quotes))
		{
			if (*s == '\'')
				in_quotes = !in_quotes;
			s++;
		}
	}
	return (count);
}

static int	length_word(char const *s, char sep)
{
	int	length;
	int	in_quotes;

	length = 0;
	in_quotes = 0;
	while (*s != '\0' && (*s != sep || in_quotes))
	{
		if (*s == '\'')
			in_quotes = !in_quotes;
		else
			length++;
		s++;
	}
	return (length);
}

static char	*ft_word(char const *str, char sep)
{
	int		i;
	int		j;
	int		size;
	int		in_quotes;
	char	*word;

	i = 0;
	j = 0;
	in_quotes = 0;
	size = length_word(str, sep);
	word = (char *)malloc(size + 1);
	if (!word)
		return (NULL);
	while (size > 0)
	{
		if (str[i] == '\'')
			in_quotes = !in_quotes;
		else
		{
			word[j++] = str[i];
			size--;
		}
		i++;
	}
	return (word[j] = '\0', word);
}

char	**ft_split_args(char const *s, char c)
{
	char	**strings;
	int		i;
	int		in_quotes;

	i = 0;
	in_quotes = 0;
	if (s[0] == '\0')
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*s != '\0')
	{
		skip_separator(&s, c, &in_quotes);
		if (*s != '\0')
		{
			strings[i] = ft_word(s, c);
			if (!strings[i])
				return (free_split(strings, i));
			i++;
		}
		skip_word(&s, c, &in_quotes);
	}
	strings[i] = 0;
	return (strings);
}
