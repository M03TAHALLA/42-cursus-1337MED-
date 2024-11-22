/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:46:55 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/07 16:36:18 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			numb[10];
	int				i;

	if (fd < 0)
		return ;
	i = 0;
	num = n;
	if (n < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (n == 0)
		write (fd, "0", 1);
	while (num > 0)
	{
		numb[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	while (i > 0)
		write (fd, &numb[--i], 1);
}
