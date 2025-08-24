/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:56:34 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/17 22:58:31 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	if (!str1 && !str2)
		return (0);
	if (!str1)
		return (-1);
	if (!str2)
		return (1);
	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	while (*new_str1 && *new_str2 && *new_str1 == *new_str2)
	{
		new_str1++;
		new_str2++;
	}
	return (*new_str1 - *new_str2);
}
