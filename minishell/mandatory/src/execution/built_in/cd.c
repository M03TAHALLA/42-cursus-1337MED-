/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:53:57 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 17:42:08 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	handle_expansion_error(char *oldpwd)
{
	write(2, "cd: error expanding target path\n", 31);
	free(oldpwd);
	return (1);
}

int	handle_empty_target(char **expanded_target, char **envp, char *oldpwd)
{
	char	*home;

	free(*expanded_target);
	home = get_env_value("HOME", envp);
	if (!home || home[0] == '\0')
	{
		write(2, "cd: HOME not set\n", 17);
		free(oldpwd);
		return (1);
	}
	*expanded_target = home;
	return (0);
}

int	builtin_cd(char **args, char **envp, int last_exit_status)
{
	char	*target;
	char	*oldpwd;
	char	*expanded_target;
	int		result;

	target = NULL;
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (perror("cd"), 1);
	if (handle_special_cases(args, envp, &target, oldpwd))
		return (1);
	if (!target && handle_env_var(args, &target, oldpwd, envp))
		return (1);
	if (!target)
		target = args[1];
	expanded_target = expand_argument(target, envp, &last_exit_status, 0);
	if (!expanded_target)
		return (handle_expansion_error(oldpwd));
	if (expanded_target[0] == '\0' 
		&& handle_empty_target(&expanded_target, envp, oldpwd))
		return (1);
	result = change_directory(expanded_target, oldpwd, envp);
	if (expanded_target != get_env_value("HOME", envp))
		free(expanded_target);
	return (result);
}
