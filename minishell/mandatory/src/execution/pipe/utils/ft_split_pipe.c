/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:39:31 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 11:59:27 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**free_split_pipe(char **strings, int i)
{
	while (i > 0)
	{
		i--;
		free(strings[i]);
	}
	free(strings);
	return (NULL);
}

static int	count_strings_pipe(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == sep)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != sep)
			s++;
	}
	return (count);
}

static int	lenght_word(char const *s, char sep)
{
	int	lenght;

	lenght = 0;
	while (*s != '\0' && *s != sep)
	{
		s++;
		lenght++;
	}
	return (lenght);
}

static	char	*ft_word(char const *str, char sep)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	size = lenght_word (str, sep);
	word = (char *)malloc(size + 1);
	if (!word)
		return (NULL);
	while (size > 0)
	{
		word[i] = str[i];
		i++;
		size--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_pipe(char const *s, char c)
{
	char	**strings;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	strings = (char **)malloc(sizeof(char *) 
			* ((count_strings_pipe (s, c)) + 1));
	if (!strings)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strings[i] = ft_word (s, c);
			if (!strings[i])
				return (free_split_pipe(strings, i));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	return (strings[i] = 0, strings);
}
