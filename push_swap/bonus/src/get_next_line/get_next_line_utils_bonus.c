/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:05 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/30 16:57:18 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	if (s1)
	{
		while (s1[len1] != '\0')
			len1++;
	}
	if (s2)
	{
		while (s2[len2] != '\0')
			len2++;
	}
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strcpy(result, s1);
	if (s2)
		ft_strcpy(result + len1, s2);
	return (result);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n && s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
	result[n] = '\0';
	return (result);
}

char	*ft_strdup(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (ft_strndup(s, len));
}

char	*ft_strchr_get(char *s, int c)
{
	char	sp;
	int		i;

	sp = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == sp)
			return (&s[i]);
		i++;
	}
	if (s[i] == sp)
		return (&s[i]);
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i; 

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
