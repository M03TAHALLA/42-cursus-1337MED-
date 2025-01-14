/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:04:17 by mtahalla          #+#    #+#             */
/*   Updated: 2025/01/10 11:10:39 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strlen_printf(const char *str);
int		base_nbr(unsigned long nbr, const char *base);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putadd(unsigned long p);
int		ft_putnbr(int nb);

#endif