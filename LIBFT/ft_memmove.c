/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:10:04 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/08 10:06:19 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destp;
	const unsigned char	*srcp;

	if (dest == src)
		return (dest);
	if (dest > src)
	{
		destp = dest + n;
		srcp = src + n;
		while (n-- > 0)
		{
			*--destp = *--srcp;
		}
	}
	else
	{
		destp = dest;
		srcp = src;
		while (n-- > 0)
		{
			*destp++ = *srcp++;
		}
	}
	return (dest);
}
