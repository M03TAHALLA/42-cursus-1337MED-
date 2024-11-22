/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:20:15 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/09 16:56:52 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	mult;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	mult = count * size;
	if (mult == 0)
	{
		str = malloc(0);
		if (!str)
			return (0);
		return (str);
	}
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero (str, (count * size));
	return (str);
}
