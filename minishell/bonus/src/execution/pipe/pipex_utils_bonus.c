/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:41:44 by mtahalla          #+#    #+#             */
/*   Updated: 2025/04/05 12:02:10 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*check_access(char *cmd, char **paths)
{
	int		i;
	char	*cmd_join;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin_pipe(paths[i], "/");
		cmd_join = ft_strjoin_pipe(temp, cmd);
		free(temp);
		if (access(cmd_join, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (cmd_join);
		}
		free(cmd_join);
		i++;
	}
	return (NULL);
}

char	*get_env_path(char **env, int i)
{
	char	*path;

	while (env[i])
	{
		if (ft_strnstr_pipe(env[i], "PATH=", 5))
		{
			path = ft_strnstr_pipe(env[i], "PATH=", 5) + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env, int i)
{
	char	*path;
	char	**paths;

	path = NULL;
	execute_script(cmd);
	if (access(cmd, F_OK | X_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	path = get_env_path(env, i);
	if (path)
	{
		paths = ft_split_pipe(path, ':');
		path = check_access(cmd, paths);
		if (path)
			return (path);
		free_split(paths);
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

char	*execute_script(char *cmd)
{
	int		fd;
	char	buf[3];

	fd = open(cmd, O_RDONLY);
	if (fd >= 0)
	{
		if (read(fd, buf, 2) == 2 && buf[0] == '#' && buf[1] == '!')
		{
			close(fd);
			if (access("/bin/bash", F_OK | X_OK) == 0)
				return (cmd);
		}
		close(fd);
	}
	return (NULL);
}
