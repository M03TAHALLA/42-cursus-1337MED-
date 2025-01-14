/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:54:17 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/26 13:33:20 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_putstr("0x0"));
	write(1, "0x", 2);
	count += 2;
	count += base_nbr(p, "0123456789abcdef");
	return (count);
}
