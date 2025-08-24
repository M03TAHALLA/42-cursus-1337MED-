/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_help_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalyout <fbalyout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:33:24 by fbalyout          #+#    #+#             */
/*   Updated: 2025/05/18 15:32:17 by fbalyout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

int	ft_is_cmd(char *arg)
{
	if ((!ft_strcmp(arg, "||") || !ft_strcmp(arg, "&&") || !ft_strcmp(arg, "|")
			|| !ft_strcmp(arg, "<<") || !ft_strcmp(arg, ">>") || !ft_strcmp(arg,
				"<") || !ft_strcmp(arg, ">") || !ft_strcmp(arg, "(")
			|| !ft_strcmp(arg, ")")) && arg[0] != '\'' && arg[0] != '\"')
	{
		return (0);
	}
	return (1);
}
