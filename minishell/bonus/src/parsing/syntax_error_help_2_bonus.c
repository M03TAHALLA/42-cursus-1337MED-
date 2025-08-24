/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_help_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:02:11 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/12 10:11:58 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	ft_is_op(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "||") || !ft_strcmp(str, "&&"))
		return (1);
	return (0);
}

int	ft_check_initial(char *str1, char *str2)
{
	if (ft_is_red(str1) || !ft_strcmp(str1, "<>") || ft_is_op(str1))
	{
		if (!str2 || !ft_is_cmd(str2))
		{
			if (!str2)
			{
				ft_putstr_fd("ShellNote: syntax error near unexpected token ",
					2);
				ft_putstr_fd("`newline'\n", 2);
			}
			else
				print_error(str2);
			return (1);
		}
	}
	return (0);
}

int	check_redirection(char **args, int i)
{
	if (args[i + 1] == NULL || !ft_is_cmd(args[i + 1]))
	{
		print_error(args[i + 1]);
		return (1);
	}
	return (0);
}

int	check_operator(char **args, int i)
{
	if (i == 0 || !args[i + 1] || ft_is_op(args[i + 1]) || (i > 0
			&& ft_is_op(args[i - 1])))
	{
		if (!args[i + 1])
			print_error(NULL);
		else
			print_error(args[i]);
		return (1);
	}
	return (0);
}

int	check_open_paren(char **args, int i)
{
	if (args[i + 1] == NULL || (i > 0 && ft_is_cmd(args[i - 1]))
		|| !ft_is_cmd(args[i + 1]))
	{
		if (args[i + 1])
			print_error(args[i + 1]);
		else
			print_error(NULL);
		return (1);
	}
	return (0);
}
