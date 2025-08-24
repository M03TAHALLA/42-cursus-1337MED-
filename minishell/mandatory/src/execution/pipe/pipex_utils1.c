/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:48:02 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/13 10:24:04 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_permission_error(char *path)
{
	ft_putstr_fd("ShellNote: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	exit(126);
}

void	handle_not_found_error(char *path)
{
	ft_putstr_fd("ShellNote: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(127);
}

void	try_execute_path(char **args, char **env)
{
	if (execve(args[0], args, env) == -1)
	{
		perror("ShellNote");
		free_args(args);
		exit(EXIT_FAILURE);
	}
}

void	execute_direct_path(char **args, char **env)
{
	struct stat	sb;

	if (stat(args[0], &sb) != 0)
	{
		handle_not_found_error(args[0]);
		free_args(args);
		return ;
	}
	if (S_ISDIR(sb.st_mode))
	{
		handle_directory_error(args[0]);
		free_args(args);
		return ;
	}
	if (access(args[0], X_OK) != 0)
	{
		handle_permission_error(args[0]);
		free_args(args);
		return ;
	}
	try_execute_path(args, env);
}

void	execute_from_path(char **args, char **env)
{
	char	*path;

	path = ft_get_path(args[0], env, 0);
	args = expand_wildcards_in_args(args);
	if (!path)
	{
		ft_putstr_fd("ShellNote: command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	if (execve(path, args, env) == -1)
	{
		perror("ShellNote");
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
}
