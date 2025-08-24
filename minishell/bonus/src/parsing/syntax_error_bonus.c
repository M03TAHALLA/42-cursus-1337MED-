/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:12:14 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/18 16:14:44 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	check_close_paren(char **args, int i)
{
	if (i == 0 || !ft_is_cmd(args[i - 1]) || (args[i + 1] && !ft_is_op(args[i
					+ 1]) && !ft_is_red(args[i + 1])))
	{
		if (args[i + 1] && !ft_is_op(args[i + 1]) && !ft_is_red(args[i + 1]))
			print_error(args[i + 1]);
		else
			print_error(NULL);
		return (1);
	}
	return (0);
}

int	check_token(char **args, int i)
{
	if (check_quotes(args[i]))
		return (1);
	if (ft_is_red(args[i]))
	{
		if (check_redirection(args, i))
			return (1);
	}
	else if (ft_is_op(args[i]))
	{
		if (check_operator(args, i))
			return (1);
	}
	else if (!ft_strcmp(args[i], "("))
	{
		if (check_open_paren(args, i))
			return (1);
	}
	else if (!ft_strcmp(args[i], ")"))
	{
		if (check_close_paren(args, i))
			return (1);
	}
	return (0);
}

int	syntax_error(char **args)
{
	int	i;

	i = 0;
	if (args == NULL || args[0] == NULL)
		return (0);
	if (check_parentheses(args) || ft_check_initial(args[0], args[1]))
		return (1);
	while (args[i])
	{
		if (check_token(args, i))
			return (1);
		i++;
	}
	return (0);
}
