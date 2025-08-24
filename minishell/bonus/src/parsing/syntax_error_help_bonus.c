/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:09:32 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/13 17:52:48 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	check_dquotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count++;
		i++;
	}
	if (count % 2 != 0)
	{
		ft_putstr_fd("ShellNote: syntax error near unexpected token `\"\n", 2);
		return (1);
	}
	return (0);
}

int	check_squotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		i++;
	}
	if (count % 2 != 0)
	{
		ft_putstr_fd("ShellNote: syntax error near unexpected token `\'\n", 2);
		return (1);
	}
	return (0);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
			{
				if (check_squotes(str + i))
					return (1);
				i++;
				while (str[i] && str[i] != '\'')
					i++;
			}
			else if (str[i] == '\"')
			{
				if (help_dquote(str, &i))
					return (1);
			}
		}
		i++;
	}
	return (0);
}

void	print_error(char *str)
{
	ft_putstr_fd("ShellNote: syntax error near unexpected token `", 2);
	if (str)
		ft_putstr_fd(str, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
}

int	ft_is_red(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, ">") || !ft_strcmp(str, ">>")
		|| !ft_strcmp(str, "<<"))
		return (1);
	return (0);
}
