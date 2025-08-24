/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:06:31 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 10:03:48 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_bonus.h"

static int	check_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static int	is_valid_number(const char *str, long *result)
{
	int		sign;
	long	num;
	int		i;

	sign = 1;
	num = 0;
	i = check_sign(str, &sign);
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > LLONG_MAX) || 
			(sign == -1 && - num < LLONG_MIN))
			return (0);
		i++;
	}
	*result = num * sign;
	return (1);
}

static void	handle_exit_error(const char *arg)
{
	print_err(": numeric argument required\n", arg);
	exit(255);
}

int	builtin_exit(char **args, int last_exit_status, bool has_pipe)
{
	long	exit_code;

	if (!has_pipe)
		print_str("exit\n");
	if (!args[1])
		exit(last_exit_status);
	if (ft_strcmp(args[1], "$?") == 0)
		exit(last_exit_status);
	if (!is_valid_number(args[1], &exit_code))
		handle_exit_error(args[1]);
	if (args[2])
	{
		print_str("minishell: exit: too many arguments\n");
		return (1);
	}
	exit((unsigned char)exit_code);
}
