/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:41:45 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/04 19:42:27 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

bool	is_quoted_dash(const char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	return ((len == 3 && arg[0] == '\'' && arg[1] == '-' && arg[2] == '\'') 
		|| (len == 3 && arg[0] == '"' && arg[1] == '-' && arg[2] == '"'));
}

bool	is_quoted_telda(const char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	return ((len == 3 && arg[0] == '\'' && arg[1] == '~' && arg[2] == '\'') 
		|| (len == 3 && arg[0] == '"' && arg[1] == '~' && arg[2] == '"'));
}

int	handle_special_cases(char **args, char **envp, char **target, char *oldpwd)
{
	if (!args[1] || ft_strcmp(args[1], "~") == 0 || is_quoted_telda(args[1]))
		return (handle_home_case(target, envp, oldpwd));
	else if (ft_strcmp(args[1], "-") == 0 || is_quoted_dash(args[1]))
		return (handle_oldpwd_case(target, envp, oldpwd));
	return (0);
}
