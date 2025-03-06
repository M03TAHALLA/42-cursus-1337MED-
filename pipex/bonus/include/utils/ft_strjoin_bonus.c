/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:40 by mtahalla          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:25 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

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
