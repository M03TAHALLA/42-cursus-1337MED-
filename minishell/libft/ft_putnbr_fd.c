/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:03:30 by fbalyout          #+#    #+#             */
/*   Updated: 2024/10/26 16:03:30 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		nbr *= (-1);
		write(fd, "-", 1);
		ft_putnbr_fd(nbr, fd);
		return ;
	}
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + 48, fd);
}
