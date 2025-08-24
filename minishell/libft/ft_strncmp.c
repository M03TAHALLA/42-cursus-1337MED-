/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:09:22 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:09:22 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (*new_str1 == *new_str2 && *new_str1 && *new_str2 && i < n - 1)
	{
		new_str1++;
		new_str2++;
		i++;
	}
	return (*new_str1 - *new_str2);
}
