/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:39:37 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 11:59:51 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp_pipe(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 > *s2)
			return ((unsigned char ) *s1 - (unsigned char) *s2);
		if (*s1 < *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
