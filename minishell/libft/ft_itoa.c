/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:48:30 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 15:48:30 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(size_t nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned long	nb;

	if (n < 0)
		nb = -(unsigned int)n;
	else
		nb = (unsigned int)n;
	len = ft_nbr_len(nb);
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
