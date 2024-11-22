/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:36:50 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/07 16:56:28 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstl;
	size_t		srcl;
	size_t		i;
	size_t		j;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstsize <= dstl)
		return (srcl + dstsize);
	i = 0;
	j = dstl;
	while (src[i] != '\0' && i < (dstsize - dstl - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstl + srcl);
}
