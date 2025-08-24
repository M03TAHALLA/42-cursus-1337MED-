/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:52 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:10:52 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*string;
	char	ch;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (string[i])
		i++;
	if (ch == '\0')
		return (&string[i]);
	while (i >= 0)
	{
		if (string[i] == ch)
			return (&string[i]);
		i--;
	}
	return (NULL);
}
