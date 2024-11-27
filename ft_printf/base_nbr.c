/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:38:32 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/26 13:24:25 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_base(const char *base)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(base);
	i = 0;
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32) 
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j]) 
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_nbr(unsigned long nbr, const char *base)
{
	unsigned long	num;
	int				base_len;
	char			result[65];
	int				count;
	int				index;

	num = nbr;
	base_len = ft_strlen(base);
	count = 0;
	index = 0;
	if (!is_valid_base(base))
		return (0);
	if (num == 0)
		return (ft_putchar(base[0]), 1);
	while (num > 0)
	{
		result[index++] = base[num % base_len];
		num /= base_len;
	}
	while (index > 0)
	{
		ft_putchar(result[--index]);
		count++;
	}
	return (count);
}
