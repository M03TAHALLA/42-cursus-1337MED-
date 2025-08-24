/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:09:02 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:09:02 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*last_s;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	last_s = (char *)malloc((i + 1) * sizeof(char));
	if (!last_s)
		return (NULL);
	j = 0;
	while (j < i)
	{
		last_s[j] = f(j, s[j]);
		j++;
	}
	last_s[j] = '\0';
	return (last_s);
}
