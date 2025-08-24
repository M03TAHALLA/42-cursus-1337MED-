/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:39:23 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/01 16:13:09 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

char	*get_env_value(const char *var, char **envp)
{
	size_t	len;
	int		i;

	len = ft_strlen(var);
	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], var, len) && envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

int	handle_env_var_error(char *arg, char *oldpwd)
{
	char	error_msg[256];

	ft_strlcpy(error_msg, "ShellNote cd: ", sizeof(error_msg));
	ft_strcat(error_msg, arg);
	ft_strcat(error_msg, ": No such file or directory\n");
	write(2, error_msg, ft_strlen(error_msg));
	free(oldpwd);
	return (1);
}

char	*extract_var_name(char *arg)
{
	char	*var_name;

	if (arg[0] == '$')
		var_name = arg + 1;
	else if (arg[0] == '\"' && arg[1] == '$')
		var_name = ft_strtrim(arg + 2, "\"");
	else
		var_name = NULL;
	return (var_name);
}
