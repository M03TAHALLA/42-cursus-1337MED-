/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:51:42 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 10:26:58 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	handle_error(const char *msg, int fd1, int fd2)
{
	perror(msg);
	close(fd1);
	close(fd2);
	exit(EXIT_FAILURE);
}

char	*expand_env_vars(char *str, char **env)
{
	char	*var_name;
	char	*var_value;
	int		start_idx;

	if (!str)
		return (NULL);
	if (str[0] == '$' || (str[0] == '"' && str[1] == '$'))
	{
		if (str[0] == '"')
			start_idx = 1;
		else
			start_idx = 0;
		var_name = ft_strdup(str + start_idx + 1);
		if (var_name && str[0] == '"' && ft_strchr(var_name, '"'))
			*ft_strchr(var_name, '"') = '\0';
		if (!var_name)
			return (ft_strdup(""));
		var_value = get_env_value(var_name, env);
		free(var_name);
		if (!var_value)
			return (ft_strdup(""));
		return (ft_strdup(var_value));
	}
	return (ft_strdup(str));
}

void	handle_empty_cmd(char *cmd)
{
	if ((cmd[0] == '"' && cmd[1] == '"' && cmd[2] == '\0')
		|| (cmd[0] == '\'' && cmd[1] == '\'' && cmd[2] == '\0'))
	{
		ft_putstr_fd("ShellNote: : command not found\n", 2);
		exit(127);
	}
}

void	handle_directory_error(char *path)
{
	ft_putstr_fd("ShellNote: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": is a directory\n", 2);
	exit(126);
}
