/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:25 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/25 21:09:09 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count = ft_putstr("(null)");
		return (count);
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}
