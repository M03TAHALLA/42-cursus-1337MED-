/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:39:48 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 12:43:10 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

size_t	ft_strlcpy_pipe(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen_pipe(src);
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while ((src[i] != '\0') && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
