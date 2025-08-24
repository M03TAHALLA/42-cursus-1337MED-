/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:39:43 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 12:43:00 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin_pipe(char const *s1, char const *s2)
{
	char	*join;
	char	*joinp;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen_pipe(s1) + ft_strlen_pipe(s2) + 1);
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
