/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:39:59 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 11:59:59 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr_pipe(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!len && !haystack && needle)
		return (0);
	if (needle[0] == '\0' || needle == haystack)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

int	count_strings(char const *s, char sep)
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
			if (*s == '"')
				in_quotes = !in_quotes;
			s++;
		}
	}
	return (count);
}
