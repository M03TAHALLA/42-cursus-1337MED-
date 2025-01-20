/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:52:40 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/04 10:26:54 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*joinp;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	joinp = join;
	if (!join)
		return (0);
	while (*s1 != '\0')
		*joinp++ = *s1++;
	while (*s2 != '\0')
		*joinp++ = *s2++;
	*joinp = '\0';
	return (join);
}
