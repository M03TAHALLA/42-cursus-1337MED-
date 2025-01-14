/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:07:57 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/10 11:15:08 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_special_case(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1); 
	}
	return (0);
}

static int	write_digits(long nbr, char *result)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		result[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	char	result[12];
	long	nbr;
	int		i;
	int		count;

	i = 0;
	count = handle_special_case(nb);
	nbr = nb;
	if (count > 0)
		return (count);
	if (nb < 0)
	{
		write(1, "-", 1);
		nbr = -nb;
		++count;
	}
	i = write_digits(nbr, result);
	while (--i >= 0)
	{
		write(1, &result[i], 1);
		count++;
	}
	return (count);
}
