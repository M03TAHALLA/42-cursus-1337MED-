/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:58:10 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/08 10:09:07 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sp;
	int		i;

	sp = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == sp)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == sp)
		return ((char *) &s[i]);
	return (0);
}
