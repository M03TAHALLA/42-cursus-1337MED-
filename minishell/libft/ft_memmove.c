/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:44:32 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/27 16:44:32 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	size_t				j;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	i = 0;
	j = 0;
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	if (p_dest <= p_src)
	{
		while (i < n && j < n)
			p_dest[i++] = p_src[j++];
	}
	else
	{
		i = n;
		j = n;
		while (i > 0 && j > 0)
			p_dest[--i] = p_src[--j];
	}
	return (dest);
}
