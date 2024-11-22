/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:21:35 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/07 19:35:18 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;
	unsigned char		val;

	ps = s;
	val = (unsigned char)c;
	while (n > 0)
	{
		if (*ps == val)
		{
			return ((void *)ps);
		}
		ps++;
		n--;
	}
	return (0);
}
