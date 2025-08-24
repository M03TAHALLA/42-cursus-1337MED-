/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_help_3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:52:00 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/22 13:49:12 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	check_parentheses(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], "("))
			count++;
		else if (!ft_strcmp(args[i], ")"))
			count--;
		if (count < 0)
		{
			ft_putstr_fd("ShellNote: syntax error with mismatched parentheses\n",
				2);
			return (1);
		}
		i++;
	}
	if (count != 0)
	{
		ft_putstr_fd("ShellNote: syntax error near unclosed parentheses\n", 2);
		return (1);
	}
	return (0);
}

int	help_dquote(char *str, int *i)
{
	if (check_dquotes(str + *i))
		return (1);
	(*i)++;
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	return (0);
}
