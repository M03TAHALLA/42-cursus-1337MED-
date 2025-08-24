/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:11:57 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/17 22:57:02 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(const char *s, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_strchr(charset, s[i]) && (ft_strchr(charset, s[i + 1]) || s[i
					+ 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*extract_word(const char *s, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && !ft_strchr(charset, s[i]))
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !ft_strchr(charset, s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	free_array(char **array, int i)
{
	if (array[i])
		return (0);
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (1);
}

static char	**allocate_array(const char *s, char *charset)
{
	char	**array;
	int		i;

	array = malloc((count_char(s, charset) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (ft_strchr(charset, *s))
			s++;
		else
		{
			array[i] = extract_word(s, charset);
			if (free_array(array, i))
				return (NULL);
			i++;
			while (*s && !ft_strchr(charset, *s))
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char *charset)
{
	if (!s)
		return (NULL);
	return (allocate_array(s, charset));
}
