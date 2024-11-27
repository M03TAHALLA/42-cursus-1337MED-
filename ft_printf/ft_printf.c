/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:23 by mtahalla          #+#    #+#             */
/*   Updated: 2024/11/26 15:46:32 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char specifier, va_list value)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar(va_arg(value, int));
	if (specifier == 's')
		count = ft_putstr(va_arg(value, char *));
	if (specifier == 'p')
		count = ft_putadd(va_arg(value, unsigned long));
	if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(value, int));
	if (specifier == 'u')
		count = base_nbr(va_arg(value, unsigned int), "0123456789");
	if (specifier == 'x')
		count = base_nbr((unsigned int )va_arg(value, int), "0123456789abcdef");
	if (specifier == 'X')
		count = base_nbr((unsigned int )va_arg(value, int), "0123456789ABCDEF");
	if (specifier == '%')
		count = write(1, "%%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (write(1, NULL, 0) == -1)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			count += check_format(*(str + 1), args);
			str++;
			count--;
		}
		else if (*str == '%')
			break ;
		else
			ft_putchar(*str);
		count++;
		str++;
	}
	return (va_end(args), count);
}
