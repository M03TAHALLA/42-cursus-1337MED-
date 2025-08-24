/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:04:02 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:04:02 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;
	char	ch;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (string[i] || ch == '\0')
	{
		if (string[i] == ch)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
