/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:32:00 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/08 10:32:35 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lenght_s;
	size_t	back;

	if (!s)
		return (NULL);
	lenght_s = ft_strlen(s);
	back = 0;
	if (start < lenght_s)
		back = lenght_s - start;
	if (back > len)
		back = len;
	sub = (char *)malloc(back + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < back)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
