/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:49:26 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/14 08:50:50 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*num_to_str(char *s, unsigned int number, int lenght_num)
{
	while (number > 0)
	{
		s[lenght_num] = number % 10 + '0';
		number = number / 10;
		lenght_num--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	char			*num;
	int				lenght_num;

	lenght_num = ft_num_len(n);
	num = malloc(sizeof(char) * lenght_num + 1);
	if (!num)
		return (NULL);
	num[lenght_num] = '\0';
	--lenght_num;
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		number = -n;
		num[0] = '-';
	}
	else
		number = n;
	num = num_to_str(num, number, lenght_num);
	return (num);
}
