/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:02:58 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/09 19:24:39 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char		*des;
	const unsigned char	*src;

	if (destination == source)
		return (destination);
	des = destination;
	src = source;
	while (size > 0)
	{
		*des = *src;
		des++;
		src++;
		size--;
	}
	return (destination);
}
