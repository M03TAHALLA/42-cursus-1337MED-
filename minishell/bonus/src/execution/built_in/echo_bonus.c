/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:24:14 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:41:54 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_bonus.h"

int	is_valid_n_option(const char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	print_arguments(char **args, int *last_exit_status, char ***envp, int i)
{
	char	*expanded;

	while (args[i])
	{
		if (ft_strcmp(args[i], "$0") == 0)
			expanded = ft_strdup("ShellNote📜💀");
		else
			expanded = expand_argument(args[i], *envp, last_exit_status, NULL);
		if (!expanded)
			return ;
		ft_putstr_fd(expanded, STDOUT_FILENO);
		free(expanded);
		if (args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
}

int	builtin_echo(char **args, int *last_exit_status, char ***envp)
{
	int	i;
	int	n_option;

	i = 1;
	n_option = 0;
	while (args[i] && is_valid_n_option(args[i]))
	{
		n_option = 1;
		i++;
	}
	print_arguments(args, last_exit_status, envp, i);
	if (!n_option)
		write(STDOUT_FILENO, "\n", 1);
	*last_exit_status = 0;
	return (0);
}
