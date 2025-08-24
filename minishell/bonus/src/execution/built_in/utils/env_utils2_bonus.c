/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:44:59 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 15:46:47 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin_bonus.h"

int	handle_env_var(char **args, char **target, char *oldpwd, char **envp)
{
	char	*var_name;
	char	*var_value;

	var_name = extract_var_name(args[1]);
	if (!var_name)
		return (0);
	var_value = get_env_value(var_name, envp);
	if (!var_value)
		return (handle_env_var_error(args[1], oldpwd));
	*target = var_value;
	return (0);
}

void	handle_chdir_error(char *target, char *oldpwd)
{
	char	error_msg[256];

	ft_strlcpy(error_msg, "ShellNote cd: ", sizeof(error_msg));
	ft_strcat(error_msg, target);
	ft_strcat(error_msg, ": ");
	ft_strcat(error_msg, strerror(errno));
	ft_strcat(error_msg, "\n");
	write(2, error_msg, ft_strlen(error_msg));
	free(oldpwd);
}

void	update_pwd_env(char *oldpwd, char **envp)
{
	char	cwd[PATH_MAX];

	update_env("OLDPWD", oldpwd, envp);
	if (getcwd(cwd, sizeof(cwd)))
		update_env("PWD", cwd, envp);
}

int	change_directory(char *target, char *oldpwd, char **envp)
{
	if (chdir(target) != 0)
	{
		handle_chdir_error(target, oldpwd);
		return (1);
	}
	update_pwd_env(oldpwd, envp);
	free(oldpwd);
	return (0);
}
