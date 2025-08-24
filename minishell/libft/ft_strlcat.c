/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:08:04 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:08:04 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	char	*source;

	source = (char *)src;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(source);
	if (size <= len_d)
		return (size + len_s);
	i = 0;
	while (source[i] && (i + len_d + 1) < size)
	{
		dest[len_d + i] = source[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
