/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:27:29 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/08 10:25:59 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	p;
	int		i;
	char	*str;

	str = 0;
	p = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == p)
			str = (char *) &s[i];
		i++;
	}
	if (s[i] == p)
		str = (char *) &s[i];
	return (str);
}
